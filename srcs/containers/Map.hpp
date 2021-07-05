#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <limits>
# include <memory>
# include <utility>
# include <cstddef>
# include "BidiMapIterator.hpp"
# include "Algorithms.hpp"
# include "Traits.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef value_type &reference;
			typedef const value_type &const_reference;
			typedef value_type *pointer;
			typedef const value_type *const_pointer;
			typedef nodemap<value_type, Key> node;
			typedef BidiMapIterator<value_type, node*> iterator;
			typedef BidiMapIterator<const value_type, node*> const_iterator;
			typedef Reverse_bidiMapIterator<value_type, node*> reverse_iterator;
			typedef Reverse_bidiMapIterator<const value_type, node*> const_reverse_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

		public:
			class value_compare : binary_function<value_type, value_type, bool>
			{
			public:
				bool operator()(const value_type &x, const value_type &y) const
				{
					return comp(x.first, y.first);	
				}
			private:
				Compare comp;
				value_compare(Compare c)
				{
					comp = c;
				}
				friend class map;
			};

		public:
		
		/* *
		 * Start Constructors
		 * */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				init();
			}
			
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				init();
				insert(first, last);
			}

			map(const map &copy)
			{
				_comp = copy._comp;
				_alloc = copy._alloc;
				init();
				
				if (!copy.empty())
					insert(copy.begin(), copy.end());
				
			}

			map &operator = (const map &asg)
			{
				if (this != &asg)
				{
					_alloc = asg._alloc;
					_comp = asg._comp;
					clear();
					if (!asg.empty())
						insert(asg.begin(), asg.end());
				}
				return (*this);
			}

			~map()
			{
				clear();
				_alloc.deallocate(_smallest_node->val, 1);
				_alloc.deallocate(_biggest_node->val, 1);
				_alloc.deallocate(_root->val, 1);
				delete _smallest_node;
				delete _biggest_node;
				delete _root;
			}

		/* *
		 * Start Constructors
		 * */


		/* *
		 * Iterators methos
		 * */

			iterator begin()
			{
				if (!_sz)
					return (iterator(_biggest_node));
				return (iterator(_smallest_node->parent));
			}

			const_iterator begin() const
			{
				if (!_sz)
					return (const_iterator(_biggest_node));
				return (const_iterator(_smallest_node->parent));
			}

			iterator end()
			{
				return (iterator(_biggest_node));
			}

			const_iterator end() const
			{
				return (const_iterator(_biggest_node));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(_biggest_node->parent));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_biggest_node->parent));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(_smallest_node));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_smallest_node));
			}

		/* *
		 * End Iterators
		 * */

		/* *
		 * Start Capacity mothods
		 * */

			bool empty() const
			{
				return (!(size()));
			}

			size_type size() const
			{
				return (_sz);
			}

			size_type max_size() const
			{
				if (typeid(Key) == typeid(bool) && typeid(T) == typeid(bool))
                	return (SIZE_T_MAX / sizeof(node));
				return (SIZE_T_MAX / (sizeof(node) + sizeof(value_type)));
			}

		/* *
		 * End capacity methos
		 * */

		/* *
		 * Start element access methos
		 * */

			mapped_type &operator [] (const key_type &k)
			{
				iterator it = find(k);
				if (it == end())
					it = insert(value_type(k, mapped_type())).first;
				return (it->second);
			}
			
		/* *
		 * End element access methos
		 * */

		
		/* *
		 * Start modifiers methods
		 * */

/******************************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
			std::pair<iterator, bool>	insert(const value_type &val)
			{
				if (empty())
				{
					_alloc.construct(_root->val, val);
					_sz++;
					return (std::make_pair(iterator(_root), true));
				}
				node *tmp = _root;
				while (tmp)
				{
					if (tmp->val->first == val.first)
						return (std::make_pair(iterator(tmp), false));
					if (value_comp()(val, *tmp->val))
					{
						if (tmp->left && tmp->left != _smallest_node)
							tmp = tmp->left;
						else
							break ;
					}
					else
					{
						if (tmp->right && tmp->right != _biggest_node)
							tmp = tmp->right;
						else
							break ;
					}
				}
				if (value_comp()(val, *tmp->val))
				{
					tmp->left = new node();
					tmp->left->val = _alloc.allocate(1);
					tmp->left->parent = tmp;
					_alloc.construct(tmp->left->val, val);
					tmp = tmp->left;
				}
				else
				{
					tmp->right = new node();
					tmp->right->val = _alloc.allocate(1);
					tmp->right->parent = tmp;
					_alloc.construct(tmp->right->val, val);
					tmp = tmp->right;
				}
				setSmallestLimit();
				setBiggestLimit();
				_sz++;
				return (std::make_pair(iterator(tmp), true));
			};

			iterator					insert(iterator position, const value_type &val)
			{
				(void)position;
				return (insert(val).first);
			};
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/******************************************************************************************/

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value,
				InputIterator>::type * = nullptr)
			{
				while (first != last)
					insert(*(first++));
			}
	

/******************************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
			void erase(iterator position)
			{
				erase(position->first);
			}

			size_type	erase(const key_type &k)
			{
				node		*tmp;
				size_type	n = count(k);
				if (!(tmp = _root->find(_root, k)))
					return (0);
				if ((!tmp->left || tmp->left == _smallest_node) && (!tmp->right || tmp->right == _biggest_node)) //if there is no elements or only smallest(before negin) or bigget(end)
				{
					if (tmp != _root) //delete a leaf from left or right
					{
						if (value_comp()(*tmp->val, *tmp->parent->val))
							tmp->parent->left = nullptr;
						else
							tmp->parent->right = nullptr;
						_alloc.deallocate(tmp->val, 1);
						delete tmp;
					}
					else	
						_alloc.destroy(_root->val);
				}
				else if ((!tmp->left || tmp->left == _smallest_node) && (tmp->right && tmp->right != _biggest_node)) //del from rigth
				{
					if (tmp != _root)
					{
						if (value_comp()(*tmp->val, *tmp->parent->val)) //if val is lower it means I'm on the left
							tmp->parent->left = tmp->right;
						else
							tmp->parent->right = tmp->right;
						tmp->right->parent = tmp->parent;
					}
					else
					{
						tmp->right->parent = nullptr;
						_root = tmp->right;
					}
					_alloc.deallocate(tmp->val, 1);
					delete tmp;
				}
				else if ((tmp->left && tmp->left != _smallest_node)	&& (!tmp->right || tmp->right == _biggest_node))
				{
					if (tmp != _root)
					{
						if (value_comp()(*tmp->val, *tmp->parent->val))
							tmp->parent->left = tmp->left;
						else
							tmp->parent->right = tmp->left;
						tmp->left->parent = tmp->parent;
					}
					else
					{
						tmp->left->parent = nullptr;
						_root = tmp->left;
					}
					_alloc.deallocate(tmp->val, 1);
					delete tmp;
				}
				else if ((tmp->left && tmp->left != _smallest_node)	&& (tmp->right && tmp->right != _biggest_node))
				{
					_alloc.destroy(tmp->val);
					_alloc.construct(tmp->val, *tmp->next()->val);

					tmp = tmp->next();
					/* Move the key and value to the new corresponding place in the tree */
					/* while (tmp->right)
					{
						_alloc.destroy(tmp->val);
						_alloc.construct(tmp->val, *tmp->next()->val);
						tmp = tmp->next();
					} */
					
					/* End moving values*/
					if (value_comp()(*tmp->val, *tmp->parent->val))
						tmp->parent->left = nullptr;
					else
					{
						if (tmp->right)
						{
							tmp->parent->right = tmp->right;
							tmp->right->parent = tmp->parent;
						}
						else
							tmp->parent->right = nullptr;
					}
					_alloc.deallocate(tmp->val, 1);
					delete tmp;
				}
				_sz--;
				setSmallestLimit();
				setBiggestLimit();
				return (n);
			};
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/******************************************************************************************/

			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					iterator aux = first++;
					erase(aux); //aux->first
				}
			}

			void swap(map &x)
			{
				map aux(x);
				x = *this;
				*this = aux;
			}
	
/******************************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
			void		clear()
			{
				iterator it = begin();
				if (_sz == 0)
					return ;
				while (_smallest_node->parent != _root)
				{
					if (_smallest_node->parent->right)
					{
						_smallest_node->parent->right->parent = _smallest_node->parent->parent;
						_smallest_node->parent->parent->left = _smallest_node->parent->right;
					}
					else
						_smallest_node->parent->parent->left = nullptr;
					_alloc.destroy(_smallest_node->parent->val);
					_alloc.deallocate(_smallest_node->parent->val, 1);
					delete _smallest_node->parent;
					setSmallestLimit();
				}
				while (_biggest_node->parent != _root)
				{
					if (_biggest_node->parent->left)
					{
						_biggest_node->parent->left->parent = _biggest_node->parent->parent;
						_biggest_node->parent->parent->right = _biggest_node->parent->left;
					}
					else
						_biggest_node->parent->parent->right = nullptr;
					_alloc.destroy(_biggest_node->parent->val);
					_alloc.deallocate(_biggest_node->parent->val, 1);
					delete _biggest_node->parent;
					setBiggestLimit();
				}
				_alloc.destroy(_root->val);
				_alloc.construct(_root->val, std::make_pair(key_type(), mapped_type()));
				_sz = 0;
			};
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/******************************************************************************************/

		/* *
		 * End modifiers methods
		 * */

		/* *
		 * Start Observers methods
		 * */

			key_compare key_comp() const
			{
				return (key_compare());
			}

			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}

		/* *
		 * End observers
		 * */

		/* *
		 * Start operations
		 * */

			iterator find(const key_type &k)
			{
				iterator it = begin();

				while (it != end())
				{
					if (compareToEqual(it->first, k))
						return (it);
					it++;
				}
				return (it);
			}

			const_iterator find(const key_type &k) const
			{
				const_iterator it = this->begin();
				
				while (it != end())
				{
					if (compareToEqual(it->first, k))
						return (it);
					it++;
				}
				return (it);
			}

			size_type count (const key_type& k) const
			{
				const_iterator it = this->begin();
				
				while (it != end())
				{
					if (compareToEqual(it->first, k))
						return (1);
					it++;
				}
				return (0);
			}

			iterator lower_bound(const key_type &k)
			{
				iterator it = this->begin();
				
				while (it != end())
				{
					if (!key_comp()(it->first, k))
						return (it);
					it++;
				}
				return (it);
			}
	
			const_iterator lower_bound(const key_type &k) const
			{
				const_iterator it = this->begin();
				
				while (it != end())
				{
					if (!key_comp()(it->first, k))
						return (it);
					it++;
				}
				return (it);
			}

			iterator upper_bound(const key_type &k)
			{
				iterator it = this->begin();
					
				while (it != end())
				{
					if (key_comp()(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}

			const_iterator upper_bound(const key_type &k) const
			{
				const_iterator it = this->begin();
				
				while (it != end())
				{
					if (key_comp()(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}

			std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (std::make_pair(lower_bound(k), upper_bound(k)));
			}

			std::pair<iterator, iterator> equal_range(const key_type& k)
			{
				return (std::make_pair(lower_bound(k), upper_bound(k)));
			}

		/* *
		 * End Operations methods
		 * */

		private:
			key_compare		_comp;
			size_type		_sz;
			node			*_root;
			node			*_biggest_node;
			node			*_smallest_node;
			node			*_ptr;
			allocator_type	_alloc;

			bool compareToEqual(key_type k1, key_type k2) const
			{
				return (!key_comp()(k1, k2) && !key_comp()(k2, k1));
			}

			void	init() {
				_root = new node();
				_biggest_node = new node();
				_smallest_node = new node();
				_root->val = _alloc.allocate(1);
				_alloc.construct(_root->val, std::make_pair(key_type(), mapped_type()));
				_smallest_node->val = _alloc.allocate(1);
				_alloc.construct(_smallest_node->val, std::make_pair(key_type(), mapped_type()));
				_biggest_node->val = _alloc.allocate(1);
				_alloc.construct(_biggest_node->val, std::make_pair(key_type(), mapped_type()));
				setSmallestLimit();
				setBiggestLimit();
				_sz = 0;
			};

			void	setSmallestLimit()
			{		
				node *aux = _root;

				while (aux->left && aux->left != _smallest_node)
					aux = aux->left;
				aux->left = _smallest_node;
				_smallest_node->parent = aux;
			}

			void	setBiggestLimit()
			{
				node *aux = _root;
				while (aux->right && aux->right != _biggest_node)
					aux = aux->right;
				aux->right = _biggest_node;
				_biggest_node->parent = aux;
			}

			void unsetLimits()
			{
				_biggest_node->parent->right = nullptr;
				_smallest_node->parent->left = nullptr;
			}
	};

	/* Non-member function overloads */
	template <class Key, class T, class Compare>
	void swap(map<Key, T, Compare> &x, map<Key, T, Compare> &y)
	{
		map<Key, T, Compare> aux(x);
		x = y;
		y = aux;
	}

	template <class Key, class T, class Compare>
	bool operator == (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		typename map<Key, T, Compare>::const_iterator right_it = rhs.begin();
		typename map<Key, T, Compare>::const_iterator left_it = lhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (left_it != lhs.end())
		{
			if (*(left_it++) != *(right_it++))
				return (false);
		}
		return (true);
	}

	template <class Key, class T, class Compare>
	bool operator != (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare>
	bool operator < (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare>
	bool operator <= (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (!(lhs > rhs));
	}

	template <class Key, class T, class Compare>
	bool operator > (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare>
	bool operator >= (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (!(lhs < rhs));
	}
};

#endif