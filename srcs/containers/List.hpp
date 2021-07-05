#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <memory>
# include <climits>
# include <cstddef>
# include <unistd.h>
# include "../includes/Node.hpp"
# include "../includes/Traits.hpp"
# include "../includes/Bidirectional_iterator.hpp"
# include "../includes/Algorithms.hpp"

namespace ft{
	template <class T, class Alloc = std::allocator<T> >
	class list {
		private:

		public:
		//Types to implement
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef value_type &reference;
			typedef const value_type &const_reference;
			typedef value_type *pointer;
			typedef const value_type *const_pointer;
			typedef size_t size_type;
			typedef node<value_type> node;
			typedef node *node_pointer;
			typedef ptrdiff_t difference_type;
			typedef bidirectional_iterator<value_type, reference, pointer,
				difference_type, node_pointer> iterator;
			typedef bidirectional_iterator<value_type, const_reference,
				const_pointer, difference_type, node_pointer> const_iterator;
			typedef reverse_bidirectional_iterator<value_type, reference, pointer,
				difference_type, node_pointer> reverse_iterator;
			typedef reverse_bidirectional_iterator<value_type, const_reference,
				const_pointer, difference_type, node_pointer> const_reverse_iterator;
		//End Types
		
		/* *
		 * Constructors, destructors and operator =
		 * */
			explicit list()
			{
				this->create();
				this->sz = 0;
			}

			explicit list(size_type n, const value_type &val = value_type())
			{
				this->create();
				this->sz = 0;
				this->assign(n, val);
			}

			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				this->create();
				this->sz = 0;
				this->assign(first, last);
			}
			
			list(const list &copy)
			{
				this->create();
				this->sz = 0;
				this->assign(copy.begin(), copy.end());
			}
			
			list &operator = (const list &asg)
			{
				this->clear();
				delete this->head;
				delete this->tail;
				this->create();
				this->assign(asg.begin(), asg.end());
				return (*this);
			}
			
			virtual ~list()
			{
				this->clear();
				this->delete_this();
			}

		/* *
		 * End Destructors, constructors and operator =
		 * */
		
		/* *
		 * Following are the itarators methods
		 * */

			iterator begin()
			{
				return (iterator(head->nxt));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(head->nxt));
			}

			iterator end()
			{
				return (iterator(tail));
			}

			const_iterator end() const
			{
				return (const_iterator(tail));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->tail->prv));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(tail->prv));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(head));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(head));
			}
			
		/* *
		 * End Iterators
		 * */

		/* *
		 * Following are the capacity methods
		 * */

			bool empty() const
			{
				return (!sz);
			}

			size_type size() const
			{
				return (sz);
			}

			size_type max_size() const
			{
				return (SIZE_T_MAX / sizeof(node));
			}

		/* *
		 * End Capacity
		 * */

		/* *
	 	 * Following are the element access methods
	 	 * */

			reference front()
			{
				return (head->nxt->val);
			}

			const_reference front() const
			{
				return (head->nxt->val);
			}

			reference back()
			{
				return (tail->prv->val);
			}

			const_reference back() const
			{
				return (tail->prv->val);
			}
			
		/* *
		 * End Element access
		 * */

		/* *
		 * Following are the modifiers methods
		 * */

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last,
				 typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				clear();
				InputIterator it = first;
				while (it != last)
					push_back(*(it++));
			}

			void assign(size_type n, const value_type &val)
			{
				size_type i = 0;

				this->clear();
				while (i < n)
				{
					this->push_back(val);
					i++;
				}
			}

			void push_front(const value_type &val)
			{
				node *newNode = new node(val);
				newNode->nxt = this->head->nxt;
				newNode->prv = this->head;
				this->head->nxt->prv = newNode;
				this->head->nxt = newNode;
				sz++;
			}

			void pop_front()
			{
				if (sz > 0)
				{
					this->head->nxt = this->head->nxt->nxt;
					delete this->head->nxt->prv;
					this->head->nxt->prv = this->head;
					sz--;
				}
			}

			void push_back(const value_type &val)
			{
				node *newNode = new node(val);
				newNode->prv = this->tail->prv;
				newNode->nxt = this->tail;
				this->tail->prv->nxt = newNode;
				this->tail->prv = newNode;
				sz++;
			}

			void pop_back()
			{
				if (sz > 0)
				{
					this->tail->prv = this->tail->prv->prv;
					delete this->tail->prv->nxt;
					this->tail->prv->nxt = this->tail;
					sz--;
				}
			}

			iterator insert(iterator position, const value_type &val)
			{
				iterator it = begin();

				if (sz == 0)
				{
					node *newNode = new node(val);
					head->nxt = newNode;
					tail->prv = newNode;
					newNode->prv = head;
					newNode->nxt = tail;
					sz++;
					return position;
				}
				node *tmp = head->nxt;
				while (it != end())
				{
					if (it == position)
					{
						node *newNode = new node(val);
						newNode->prv = tmp->prv;
						newNode->nxt = tmp;
						newNode->prv->nxt = newNode;
						tmp->prv = newNode;
						sz++;
						break ;
					}
					tmp = tmp->nxt;
					it++;
				}
				return (it);
			}

			void insert(iterator position, size_type n, const value_type &val)
			{
				iterator it = this->begin();
				node *tmp = this->head->nxt;
				while (it != this->end())
				{
					if (it == position)
					{
						while (n > 0)
						{
							node *newNode = new node(val);
							newNode->prv = tmp->prv;
							newNode->nxt = tmp;
							newNode->prv->nxt = newNode;
							tmp->prv = newNode;
							sz++;
							n--;
						}
						break ;
					}
					tmp = tmp->nxt;
					it++;
				}
			}
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value,
				InputIterator>::type * = nullptr)
			{				
				node *tmp = head->nxt;
				iterator it = begin();
				
				while (it != end())
				{
					if (it == position)
						break ;
					tmp = tmp->nxt;
					it++;
				}
				
				while (first != last)
				{
					node *newNode = new node(*first);
					newNode->prv = tmp->prv;
					newNode->nxt = tmp;
					newNode->prv->nxt = newNode;
					tmp->prv = newNode;
					sz++;
					first++;
				}
			}

			iterator erase(iterator position)
			{
				node *nodeErase = findPosition(position);
				if (nodeErase != tail)
				{
					nodeErase->nxt->prv = nodeErase->prv;
					nodeErase->prv->nxt = nodeErase->nxt;
					delete nodeErase;
					sz--;
					return (++position);
				}
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				node *pos = findPosition(first);
				difference_type n = getDistance(first, last);
				while (n > 0)
				{
					pos = pos->nxt;
					erase(pos->prv);
					n--;
				}
				return (last);
			}

			void swap(list &x)
			{
				list tmp(x);
				
				x.clear();
				iterator it = this->begin();
				while (it != this->end())
					x.push_back(*(it++));
				this->clear();
				it = tmp.begin();
				while (it != tmp.end())
					this->push_back(*(it++));
				tmp.clear();
			}

			void resize(size_type n, value_type val = value_type())
			{
				node *tmp = this->tail->prv;
				if (n < sz)
				{
					size_type size = sz - n;
					while (size)
					{
						node *deleteNode = tmp;
						tmp->prv->nxt = tail;
						tail->prv = tmp->prv;
						tmp = tmp->prv;
						delete deleteNode;
						deleteNode = tmp;
						size--;
						sz--;
					}
				}
				else if (n > sz)
				{
					while (sz < n)
						this->push_back(val);
				}
			}

			void clear() {
				while (this->size() > 0){
					this->pop_back();
				}
			}

		/* *
		 * End Modifiers
		 * */

		/* *
		 * The following are the operation methos
		 * */

			void splice(iterator position, list &x)
			{
				if (!sz)
				{
					this->head->nxt = x.head->nxt;
					x.head->nxt->prv = this->head;
					this->tail->prv = x.tail->prv;
					x.tail->prv->nxt = this->tail;
				}
				else
				{
					node *tmp = findPosition(position);
					node *x_begin = x.head->nxt;
					node *x_end = x.tail->prv;
					x_begin->prv = tmp->prv;
					tmp->prv->nxt = x_begin;
					x_end->nxt = tmp;
					tmp->prv = x_end;
				}
				x.head->nxt = x.tail;
				x.tail->prv = x.head;
				sz += x.size();
				x.sz = 0;
			}
			
			void splice(iterator position, list &x, iterator i)
			{
				insert(position, *(i));
				x.erase(i);
			}

			void splice (iterator position, list& x, iterator first, iterator last)
			{
				list<T> aux(first, last);
				iterator it = aux.begin();
				
				insert(position, aux.begin(), aux.end());
				it = x.begin();
				x.erase(first, last);
			}

			iterator remove(const value_type &val)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (*it == val)
					{
						this->erase(it);
						it = this->begin();
					}
					it++;
				}
				return (it);
			}

			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator it = begin();
				while (it != end())
				{
					if (pred(*it))
						it = erase(it);
					else
						it++;
				}
			}

			void unique()
			{
				iterator it = begin();
				iterator itNext = ++begin();
				
				while (it != end() && itNext != end())
				{
					if (*it == *itNext)
					{
						itNext++;
						it = erase(it++);
					}
					else
					{
						it++;
						itNext++;
					}
				}
			}

			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				iterator it = this->begin();
				iterator itNext = it;

				while (it != this->end() && itNext != end())
				{
					itNext++;
					if (binary_pred(*(it), *(itNext)))
					{
						erase(itNext);
						itNext = it;
						continue ;
					}
					itNext = ++it;
				}
			}

			void merge(list &x)
			{
				if (this != &x)
				{
					iterator it1 = this->begin();
					iterator it2 = x.begin();
					while (it1 != this->end() && it2 != x.end())
					{
						if (*it2 < *it1)
						{
							it1 = this->insert(it1, *it2);
							it2++;
						}
						else
							it1++;
					}
					if (it1 == this->end() && it2 != x.end())
					{
						while (it2 != x.end())
							this->push_back((*it2++));
					}
					x.clear();
				}
			}

			template <class Compare>
			void merge(list &x, Compare comp)
			{
				if (this != &x)
				{
					iterator it1 = this->begin();
					iterator it2 = x.begin();
					while (it1 != this->end() && it2 != x.end())
					{
						if (comp(*it2, *it1))
						{
							it1 = this->insert(it1, *it2);
							it2++;
						}
						else
							it1++;
					}
					if (it1 == this->end() && it2 != x.end())
					{
						while (it2 != x.end())
							this->push_back((*it2++));
					}
					x.clear();
				}
			}

			void sort()
			{
				iterator it = begin();
				iterator itNext = ++begin();
				
				while (it != end() && itNext != end())
				{
					if (*it > *itNext)
					{
						swapNodes(findPosition(it), findPosition(itNext));
						it = begin();
						itNext = ++begin();
					}
					else
					{
						it++;
						itNext++;
					}
				}
			}

			template <class Compare>
			void sort(Compare comp)
			{
				iterator it = begin();
				iterator itNext = it;

				while (it != end()/*  && itNext == end() */)
				{
					itNext++;
					if (itNext == end())
						return ;
					if (comp(*(itNext), *(it)))
					{
						splice(it, *this, itNext);
						it = begin();
						itNext = it;
					}
					else
						it++;
				}
			}

			void reverse()
			{
				list<T> listReverse;
				reverse_iterator rit = this->rbegin();
				while (rit != this->rend())
				{
					listReverse.push_back(*rit);
					rit++;
				}
				this->clear();
				iterator it = listReverse.begin();
				while (it != listReverse.end())
					this->push_back(*(it)++);
				listReverse.clear();
			}
			
		/* *
		 * End Operation methos 
		 * */

		private:
			node *head;
			node *tail;
			size_type sz;

			void create()
			{
				head = new node;
				tail = new node;
				head->nxt = tail;
				tail->prv = head;
			}

			void delete_this()
			{
				delete head;
				delete tail;
			}
			
			ptrdiff_t getDistance(iterator first, iterator last)
			{
				ptrdiff_t dist = 0;
				while (first != last)
				{
					first++;
					dist++;
				}
				return (dist);
			}

			node *findPosition(iterator position)
			{
				node *tmp = this->head->nxt;
				iterator it = this->begin();
				while (it != this->end())
				{
					if (it == position)
						return (tmp);
					tmp = tmp->nxt;
					it++;
				}
				return (tmp);
			}

			void swapNodes(node *x, node *y)
			{
				value_type tmp = x->val;
				x->val = y->val;
				y->val = tmp;
			}
	};

	template <typename T>
	bool operator==(const list<T> &lhs, const list<T> &rhs)
	{
		typename list<T>::const_iterator right_it = rhs.begin();
		typename list<T>::const_iterator left_it = lhs.begin();
		
		if (lhs.size() != rhs.size())
			return (false);
		while (left_it != lhs.end())
		{
			if (*left_it != *right_it)
				return (false);
			left_it++;
			right_it++;
		}
		return (true);
	}

	template <typename T>
	bool operator != (const list<T> &lhs, const list<T> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename T>
	bool operator < (const list<T> &lhs, const list<T> &rhs)
	{
		//http://www.cplusplus.com/reference/algorithm/lexicographical_compare/
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T>
	bool operator <= (const list<T> &lhs, const list<T> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T>
	bool operator > (const list<T> &lhs, const list<T> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T>
	bool operator >= (const list<T> &lhs, const list<T>rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T>
	void swap(list<T> &x, list<T> &y)
	{
		list<T> tmp(y);
		y = x;
		x = tmp;
	}
}
#endif
