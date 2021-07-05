#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_iterator_hpp
# include <cstddef>
# include "Traits.hpp"
# include <iostream>

namespace ft
{
	template <typename T, typename Reference, typename Pointer>
	class random_access_iterator
	{
		public:	
			typedef T value_type;
			typedef Reference reference;
			typedef const Reference &const_reference;
			typedef Pointer pointer;
			typedef const Pointer *const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef random_access_iterator_tag iterator_category;
			typedef random_access_iterator self_type;

			random_access_iterator(){
				this->element = nullptr;
			}

			random_access_iterator(pointer element) {
				this->element = element;
			}

			random_access_iterator(self_type const &copy)
			{
				this->element = copy.element;
			}

			random_access_iterator &operator = (self_type const &asg) {
				this->element = asg.element;
				return (*this);
			}

			~random_access_iterator(){}

			reference operator * () {
				return (*this->element);
			}
			
			const_reference operator * () const{
				return (*this->element);
			}

			pointer operator -> () {
				return (&(*this->element));
			}
			
			const_pointer operator -> () const {
				return (&(*this->element));
			}

			bool operator == (self_type const &rhs) const {
				if (this->element != rhs.element)
					return (false);
				return (true);
			}

			bool operator != (self_type const &rhs) const {
				if (*this == rhs)
					return (false);
				return (true);
			}

			self_type &operator ++ () {
				this->element++;
				return (*this);
			}

			self_type operator ++ (int) {
				self_type tmp(*this);
				this->element++;
				return (tmp);
			}

			self_type &operator -- () {
				this->element--;
				return (*this);
			}

			self_type operator -- (int) {
				self_type tmp(*this);
				this->element--;
				return (tmp);
			}
			
			self_type operator + (difference_type n)
			{
				self_type tmp(*this);
				tmp.element += n;
				return (tmp);
			}

			self_type operator - (difference_type n)
			{
				self_type tmp(*this);
				tmp.element -= n;
				return (tmp);
			}

			self_type operator += (difference_type n)
			{
				this->element += n;
				return (*this);
			}

			self_type operator -= (difference_type n)
			{
				this->element -= n;
				return (*this);
			}

		private:
			pointer element;
	};

	template <typename T, typename Reference, typename Pointer>
	class reverse_random_access_iterator
	{
		public:	
			typedef T value_type;
			typedef Reference reference;
			typedef const Reference &const_reference;
			typedef Pointer pointer;
			typedef const Pointer *const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef random_access_iterator_tag iterator_category;
			typedef reverse_random_access_iterator self_type;


			reverse_random_access_iterator() {
				this->element = nullptr;
			}
			
			reverse_random_access_iterator(pointer element) {
				this->element = element;
			}

			reverse_random_access_iterator(self_type const &copy) {
			
				this->element = copy.element;
			}

			self_type &operator = (self_type const &asg) {
				this->element = asg.element;
				return (*this);
			}

			~reverse_random_access_iterator() {};

			reference operator * () {
				return (*this->element);
			}
			
			const_reference operator * () const{
				return (*this->element);
			}

			pointer operator -> () { //Si no salen los valores de reverse, pon * a this (&(*this->element)
				return (&(this->element));
			}

			bool operator == (self_type const &rhs) const {
				if (this->element != rhs.element)
					return (false);
				return (true);
			}

			bool operator != (self_type const &rhs) const {
				if (*this == rhs)
					return (false);
				return (true);
			}

			self_type &operator ++ () {
				this->element--;;
				return (*this);
			}

			self_type operator ++ (int) {
				self_type tmp(*this);
				this->element--;
				return (tmp);
			}

			self_type &operator -- () {
				this->element++;
				return (*this);
			}

			self_type operator -- (int) {
				self_type tmp(*this);
				this->element++;
				return (tmp);
			}

			self_type operator + (difference_type n)
			{
				self_type tmp(*this);
				tmp.element -= n;
				return (tmp);
			}

			self_type operator - (difference_type n)
			{
				self_type tmp(*this);
				tmp.element += n;
				return (tmp);
			}

			self_type operator += (difference_type n)
			{
				this->element -= n;
				return (*this);
			}

			self_type operator -= (difference_type n)
			{
				this->element += n;
				return (*this);
			}

		private:
			pointer element;
	};
}

#endif
