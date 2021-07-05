#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Traits.hpp"
#include <cstddef>
#include <iostream>

namespace ft
{
    template <class Iterator>
    ptrdiff_t distance(Iterator first, Iterator last,
        typename ft::enable_if<!std::is_integral<Iterator>::value>::type * = 0)
        /* typename enable_if<is_iterator<typename Iterator::iterator_category>::value, Iterator>::type * = nullptr) */
    {
        ptrdiff_t n = 0;
        Iterator it = first;
        while (it != last)
        {
            it++;
            n++;
        }
        return (n);
    }

    template <class InputIterator, class Distance>
    void advance (InputIterator &pos, Distance n)
{
    int i = 0;
    
    while (i < n)
    {
        pos++;
        i++;
    }
}

template <class Iterator>
ptrdiff_t getPosition (Iterator first, Iterator pos)
{
    Iterator it = first;

    ptrdiff_t n = 0;
    while (it != pos)
    {
        it++;
        n++;
    }
    return (n);
}

template <class Arg1, class Arg2, class Result>
struct binary_function
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T>
struct less : binary_function<T, T, bool>
{
    //https://www.cplusplus.com/reference/functional/less/
    bool operator()(const T &x, const T &y) const
    {
        return (x < y);
    }
};

} // namespace ft

#endif

