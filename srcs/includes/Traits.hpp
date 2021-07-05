#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft
{

struct random_access_iterator_tag
{
};

struct bidirectional_iterator_tag
{
};

struct forward_iterator_tag
{
};

struct input_iterator_tag
{
};

struct output_iterator_tag
{
};

template <class T>
	struct Elem
	{
		Elem	*prev;
		T		*data;
		Elem	*next;

		Elem	*nxt() {
			return (this->next);
		};
		Elem	*pvs() {
			return (this->prev);
		};
	};
	
/* template <class T>
struct iterator_traits<T*>
{
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef t& reference;
	typedef random_access_iterator_tag iterator_category;
}; */
/*Falta implementar estos structs pero primero mira para que sirven y si están en el original*/
template <bool B, class T = void>
struct enable_if
{
};

template <class T>
struct enable_if<true, T>
{
	typedef T type;
};

template <bool is_iterator, typename T>
struct iterator_result
{
	typedef T type;
	static const bool value = is_iterator;
};

template <typename>
struct iterator_check : public iterator_result<false, bool>
{
};

template <>
struct iterator_check<random_access_iterator_tag>
	: public iterator_result<true, random_access_iterator_tag>
{
};

template <>
struct iterator_check<bidirectional_iterator_tag>
	: public iterator_result<true, bidirectional_iterator_tag>
{
};

template <>
struct iterator_check<forward_iterator_tag>
	: public iterator_result<true, forward_iterator_tag>
{
};

template <>
struct iterator_check<input_iterator_tag>
	: public iterator_result<true, input_iterator_tag>
{
};

template <typename T>
struct is_iterator : public iterator_check<T>
{
};

	/*******************************************************/
	/*******************************************************/
	/*******************************************************/

template<class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*(first1) == *(first2)))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};
/*
 *	http://www.cplusplus.com/reference/algorithm/lexicographical_compare/
 */
	template<class InputIterator1, class InputIterator2>
  	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	};
	/*******************************************************/
	/*******************************************************/
	/*******************************************************/
} // namespace ft

#endif
