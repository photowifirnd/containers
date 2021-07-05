#ifndef QUEUE_HPP
# define QUEUE_HPP
# include <iostream>
# include "List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class queue : public Container 
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

		/* *
		 * Start constructors: Class heritance from List<T>
		 * */

			explicit queue(const container_type &ctnr = container_type()) 
			{
				c = ctnr;
			}
			
		/* *
		 * End constructors: Class heritance from List<T>
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
		 * Start Access functions
		 * */
		
			value_type &front()
			{
				return (*c.begin());
			}

			const value_type &front() const
			{
				return (*c.begin());
			}

			value_type &back()
			{
				typename Container::iterator it = this->c.end();
				it--;
				return (*it);
			}

			const value_type &back() const
			{
				typename Container::iterator it = this->c.end();
				it--;
				return (*it);
			}
					
		/* *
		 * End Access functions
		 * */
							
		/* *
		 * Start modifier functions
		 * */
		
			void push(const value_type &val)
			{
				return (c.push_back(val));
			}

			void pop()
			{
				return (c.pop_front());
			}
					
		/* *
		 * End capacity functions
		 * */
		
		private:
			container_type c;
			
			template <class S, class C>
			friend bool operator == (const queue<S, C> &lhs, const queue<S, C> &rhs);
			template <class S, class C>
			friend bool operator < (const queue<S, C> &lhs, const queue<S, C> &rhs);
			template <class S, class C>
        	friend bool operator <= (const queue<S, C> &lhs, const queue<S, C> &rhs);
			template <class S, class C>
			friend bool operator > (const queue<S, C> &lhs, const queue<S, C> &rhs);
			template <class S, class C>
        	friend bool operator >= (const queue<S, C> &lhs, const queue<S, C> &rhs);
	};

	template <class T, class Container>
	bool operator == (const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		typename queue<T, Container>::const_iterator left_it = lhs.c.begin();
		typename queue<T, Container>::const_iterator right_it = rhs.c.begin();

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
	bool operator != (const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator < (const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		typename queue<T, Container>::const_iterator left_it = lhs.c.begin();
		typename queue<T, Container>::const_iterator right_it = rhs.c.begin();
		
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
	bool operator <= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		 return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool operator > (const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		typename queue<T, Container>::const_iterator left_it = lhs.c.begin();
		typename queue<T, Container>::const_iterator right_it = rhs.c.begin();

		if (lhs == rhs)
			return (false);
		while (left_it != lhs.c.end())
		{
			if (*(left_it++) < *(right_it++))
				return (false);
		}
		return (true);
	}

	template <class T, class Container>
	bool operator >= (const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	}

}
#endif
