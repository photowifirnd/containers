#ifndef STACK_HPP
# define STACK_HPP
# include <iostream>
# include "List.hpp"
# include "Vector.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class stack : public Container
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
		public:
					
		/* *
		 * Start Constructors: class heritance from List<T>
		 * */
		
			explicit stack(const container_type &cntr = container_type())
			{
				c = cntr;
			}
					
		/* *
		 * End Constructors: class heritance from List<T>
		 * */
							
		/* *
		 * Start capacity functions
		 * */
		
			bool empty() const
			{
				return (c.empty());
			}

			size_type size() const
			{
				return (c.size());
			}
					
		/* *
		 * End capacity functions
		 * */
							
		/* *
		 * Start access elements
		 * */
		
			value_type &top()
			{
				typename Container::iterator it = c.end();
				it--;
				return (*it);
			}

			const value_type &top() const
			{
				typename Container::const_iterator it = (c.end() - 1);
				return (*it);
			}

			void push(const value_type &val)
			{
				c.push_back(val);
			}

			void pop()
			{
				c.pop_back();
			}
					
		/* *
		 * End access elements functions
		 * */
		
			template <class S, class C>
			friend bool operator == (const stack<S, C> &lhs, const stack<S, C> &rhs);
			template <class S, class C>
			friend bool operator < (const stack<S, C> &lhs, const stack<S, C> &rhs);
			template <class S, class C>
			friend bool operator > (const stack<S, C> &lhs, const stack<S, C> &rhs);

		private:
			container_type c;
	};

	template <class T, class Container>
	bool operator == (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		typename stack<T, Container>::const_iterator left_it = lhs.c.begin();
		typename stack<T, Container>::const_iterator right_it = rhs.c.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (left_it != lhs.c.end())
		{
			if (*(left_it++) != *(right_it++))
				return (false);
		}

		return (true);
	}

	template <class T, class Container>
	bool operator != (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator < (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		typename stack<T, Container>::const_iterator left_it = lhs.c.begin();
		typename stack<T, Container>::const_iterator right_it = rhs.c.begin();

		if (lhs == rhs)
			return (false);
		while (left_it != lhs.c.end())
		{
			if (*(left_it++) > *(right_it++))
				return (false);
		}
		return (true);
	}

	template <class T, class Container>
	bool operator <= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Container>
	bool operator > (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator >= (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif
