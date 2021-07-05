/*
 * https://sinusoid.es/immer/containers.html
 * http://www.cplusplus.com/reference/vector/
 */
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "../includes/Traits.hpp"
# include "../includes/Algorithms.hpp"
# include "../includes/Random_iterator.hpp"
# include <climits>
# include <iostream>
# include <string>
# include <stdexcept>
# include <unistd.h>

namespace ft
{
	template <class T, class Alloc = std::allocator <T> >
	class vector
	{
		public:
		//Types to implement
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef value_type &reference;
			typedef const value_type &const_reference;
			typedef value_type *pointer;
			typedef const value_type *const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef random_access_iterator<value_type, reference, pointer> iterator;
			typedef random_access_iterator<value_type, const_reference,
				const_pointer> const_iterator;
			typedef reverse_random_access_iterator<value_type, reference, pointer> reverse_iterator;
			typedef reverse_random_access_iterator<value_type, const_reference,
				const_pointer> const_reverse_iterator;
		//End Types
			
		/* *
		 * Constructors, destructor and asignation: coplien's form
		 * */

			explicit vector()
			{
				element = nullptr;
				sz = 0;
				virtual_sz = 0;
			}

			explicit vector(size_type n, const value_type &val = value_type())
			{
				element = new value_type[n];
				sz = n;
				virtual_sz = n;
				assign(n, val);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type(),
			typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				element = nullptr;
				virtual_sz = 0;
				sz = 0;
				while (first != last)
					push_back(*(first++));
			}

			vector(const vector &copy)
			{
				this->virtual_sz = copy.virtual_sz;
				this->sz = copy.sz;
				this->element = new value_type[copy.virtual_sz];
				this->assign(copy.begin(), copy.end());
			}

			vector &operator = (const vector &asg)
			{
				if (element != nullptr)
					delete[] element;
				element = new value_type[asg.virtual_sz];
				assign(asg.begin(), asg.end());
				virtual_sz = asg.virtual_sz;
				sz = asg.sz;
				return (*this);
			}

			~vector()
			{
				if (element != nullptr)
					delete[] element;
			}
			
		/* *
		 * Constructors, destructor and asignation: coplien's form
		 * */

		/* *
		 * Start iterators methods
		 * */

			iterator begin()
			{
				return (iterator(element));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(this->element));
			}

			iterator end()
			{
				return (iterator(&element[sz]));
			}

			const_iterator end() const
			{
				return (const_iterator(&element[sz]));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(&(element[sz - 1])));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(&(element[sz - 1])));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(&element[SIZE_T_MAX]));
			}
			
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(&element[SIZE_T_MAX]));
			}

		/* *
		 * End Iterators
		 * */

		/* *
		 * Start capacity methods
		 * */

			size_type size() const
			{
				return (sz);
			}

			size_type max_size() const
			{
				if (typeid(T) == typeid(bool))
				{
                	return (SIZE_T_MAX / (sizeof(Alloc) + sizeof(T)));
				}
				return (SIZE_T_MAX / sizeof(value_type));
			}

			void resize(size_type n, value_type val = value_type())
			{
				size_type aux_sz = sz;

				if (n < sz)
				{
					while (n < aux_sz)
					{
						pop_back();
						n++;
					}
				}
				else if (n > sz)
				{
					while (aux_sz < n)
					{
						push_back(val);
						aux_sz++;
					}
				}
			}

			size_type capacity() const
			{
				return (virtual_sz);
			}

			bool empty() const
			{
				return (!sz);
			}

			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("Vector");
				if (!element)
					element = new value_type[n];
				if (n > virtual_sz)
				{
					value_type *aux_element = new value_type[n]; 
					virtual_sz = n; 
					if (element != nullptr)
					{
						for (size_t i = 0; i < sz; i++)
							aux_element[i] = element[i];
						delete[] element;
						element = nullptr;
					}
					element = aux_element;
				}
			}

		/* *
		 * End Capacity methods
		 * */

		/* *
		 * Start operators methods
		 * */

			reference operator [] (size_type n)
			{
				return (element[n]);
			}

			const_reference operator [] (size_type n) const
			{
				return (element[n]);
			}

			reference at(size_type n)
			{
				// en at pon std::out_of_range("Vector")
				if (n >= sz)
					throw std::out_of_range("vector");
				else
					return (element[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= sz)
					throw std::out_of_range("vector");
				else
					return (element[n]);
			}

			reference front()
			{
				return (element[0]);
			}

			const_reference front() const
			{
				return (element[0]);
			}

			reference back()
			{
				return (element[sz - 1]);
			}
			
			const_reference back() const
			{
				return (element[sz - 1]);
			}

		/* *
		 * End element Access methods
		 * */

		/* *
		 * Start modifiers methods
		 * */

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				
				size_type n = distance(first, last);
				size_type size = (n >= virtual_sz) ? n : virtual_sz;
				
				value_type *aux_element = new value_type[size];
				for (size_t i = 0; i < n; i++)
					aux_element[i] = *(first++);
				clear();
				reserve(size);
				sz = n;
				if (element != nullptr)
					delete[] element;
				element = aux_element;
			}

			void assign(size_type n, const value_type &val)
			{
				size_type i = 0;
				
				clear();
				reserve(n);
				sz = n;
				while (i < n)
					element[i++] = val;
				sz = n;
			}

			void push_back(const value_type &val)
			{
				if (element == nullptr || virtual_sz == 0)
					assign(1, val);
				else
				{
				    if (sz >= virtual_sz)
						reserve(virtual_sz * 2);
					element[sz] = val;
					sz++;
				}
			}

			void pop_back()
			{
				if (sz == 1)
					clear();
				else
					sz--;
			}

			iterator insert (iterator position, const value_type& val)
			{

				size_type	i = 0;
				iterator	aux = begin();

				while (aux != position)
				{
					i++;
					aux++;
				}
				if (sz >= virtual_sz)
				{
					if (virtual_sz == 0)
						reserve(1);
					else if (sz >= virtual_sz)
							reserve(virtual_sz * 2);
				}
				size_type	j = sz;
				while (j > i)
				{
					element[j] = element[j - 1];
					j--;
				}
				element[i] = val;
				sz++;
				position = iterator(&element[i]);
				
				return (position);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n > 0)
				{
					position = insert(position, val);
					n--;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
			{
				while (first != last)
				{
					position = insert(position, *(first));
					first++;
					position++;
				}
			}

			iterator erase (iterator position)
			{
				for (iterator it = position; it != end() - 1; it++)
					*it = *(it + 1);
				sz--;
				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				size_t i = getPosition(first);
				size_t j = getPosition(last);
				iterator ret = begin() + i;
				
				for (size_t k = i; k < j; k++)
				{
					ret = erase(ret);
				}
				return (ret);
			}

			void swap(vector &x)
			{
				vector tmp(x);
				x = *this;
				*this =tmp;
			}

			void clear()
			{
				if (element != nullptr)
					delete[] element;
				element = nullptr;
				sz = 0;
				virtual_sz = 0;
			}

		/* *
		 * End modifiers methods
		 * */

		private:
			pointer element;
			size_type virtual_sz;
			size_type sz;

			ptrdiff_t getPosition(iterator position)
			{
				ptrdiff_t n = 0;
				iterator it = begin();
				while (it != position)
				{
					it++;
					n++;
				}
				return (n);
			}
	};

/* *
* Start Non-Member methods
* */

	template <typename T>
	void swap(vector<T> &x, vector<T> &y)
	{
		vector<T> tmp(y);
		y = x;
		x = tmp;
	}

	template <typename T>
	bool operator == (const vector<T> &lhs, const vector<T> &rhs)
	{
		typename vector<T>::const_iterator rhs_it = rhs.begin();
		typename vector<T>::const_iterator lhs_it = lhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (lhs_it != lhs.end())
		{
			if (*lhs_it != *rhs_it)
				return (false);
			lhs_it++;
			rhs_it++;
		}
		return (true);
	}

	template <typename T>
	bool operator != (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <typename T>
	bool operator < (const vector<T> &lhs, const vector<T> &rhs)
	{
		//http://www.cplusplus.com/reference/algorithm/lexicographical_compare/
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T>
	bool operator <= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs > rhs));
	}

	template <typename T>
	bool operator > (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T>
	bool operator >= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs < rhs));
	}

/* *
* End Non-Member methods
* */
}

#endif
