#ifndef BIDIMAPITERATPR_HPP
# define BIDIMAPITERATPR_HPP
/* # include <cstddef>
# include <iostream> */
# include "Traits.hpp"
# include "NodeMap.hpp"

namespace ft
{
	template <class T, class P>
	class BidiMapIterator
	{
		public:
			typedef BidiMapIterator iterator;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef P node_pointer;
			typedef BidiMapIterator self_type;
			typedef bidirectional_iterator_tag iterator_category;
			typedef size_t size_type;

		/* *
		 * Start constructors, destructor and asignation: Coplien's form
		 * */

			BidiMapIterator()
			{
				_element = nullptr;
			}

			BidiMapIterator(node_pointer obj)
			{
				_element = obj;
			}

			BidiMapIterator(const iterator &copy)
			{
				_element = copy._element;
			}

			iterator &operator = (const iterator &asg)
			{
				_element = asg._element;
				return (*this);
			}

			~BidiMapIterator()
			{

			}

		/* *
		 * End constructors, destructor and asignation: Coplien's form
		 * */

		/* *
		 * Start Operators overloads for Bidirectional Map iterator 
		 * */

			bool operator == (const iterator &it) const /***/
			{
				return (_element->val == it._element->val \
				&& _element->prev() == it._element->prev() \
				&& _element->next() == it._element->next());
			}

			bool	operator != (const iterator &it) const {
				return (!(*this == it));
			}

			reference	operator * () const {
				return (*_element->val);
			}

			pointer		operator -> () const { /***/
				return (&(operator*()));
			}

			iterator	&operator ++ () {
				if (_element && _element->next())
					_element = _element->next();
				return (*this);
			}

			iterator	operator ++ (int) {
				iterator aux(*this);
				operator++();
				return (aux);
			}

			iterator	&operator -- () {
				if (_element && _element->prev())
					_element = _element->prev();
				return (*this);
			}

			iterator	operator -- (int) {
				iterator aux(*this);
				operator--();
				return (aux);
			}

		/* *
		 * End Operators overloads for Bidirectional Map iterator 
		 * */

		private:
			node_pointer	_element;
	};

	template <class T, class P>
	class Reverse_bidiMapIterator
	{
		public:
			typedef Reverse_bidiMapIterator iterator;
			typedef T value_type;
			typedef ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef P node_pointer;
			typedef Reverse_bidiMapIterator self_type;
			typedef size_t size_type;

		/* *
		 * Start constructors, destructor and asignation: Coplien's form
		 * */

			Reverse_bidiMapIterator()
			{
				_element = nullptr;
			}

			Reverse_bidiMapIterator(node_pointer obj)
			{
				_element = obj;
			}

			Reverse_bidiMapIterator(const iterator &copy)
			{
				_element = copy._element;
			}

			iterator	&operator = (const iterator &asg)
			{
				_element = asg._element;
				return (*this);
			}

			~Reverse_bidiMapIterator()
			{

			}

		/* *
		 * End constructors, destructor and asignation: Coplien's form
		 * */


		/* *
		 * Start Operators overloads for Reverse_Bidirectional Map iterator 
		 * */

			bool	operator == (const iterator &it) const
			{
				return (_element->val == it._element->val \
				&& _element->prev() == it._element->prev() \
				&& _element->next() == it._element->next());
			}

			bool	operator != (const iterator &it) const
			{
				return (!(*this == it));
			}

			reference	operator * () const
			{
				return (*_element->val);
			}

			pointer		operator -> () const
			{
				return (&(operator*()));
			}

			iterator	&operator ++ ()
			{
				if (_element && _element->prev())
					_element = _element->prev();
				return (*this);
			}

			iterator	operator ++ (int)
			{
				iterator aux(*this);
				operator++();
				return (aux);
			}

			iterator	&operator -- ()
			{
				if (_element && _element->next())
					_element = _element->next();
				return (*this);
			}

			iterator	operator -- (int)
			{
				iterator aux(*this);
				operator--();
				return (aux);
			}

		/* *
		 * End Operators overloads for Reverse_Bidirectional Map iterator 
		 * */

		private:
			node_pointer	_element;
	};
};

#endif