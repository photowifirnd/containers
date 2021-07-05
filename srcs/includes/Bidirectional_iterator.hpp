#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include <cstddef>
# include "Traits.hpp"

namespace ft
{
/*	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};*/

	template <typename T, typename Reference, typename Pointer, typename Distance, typename Node>
	class bidirectional_iterator
	{
		public:	
			typedef T value_type;
			typedef Reference reference;
			typedef Pointer pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef Node node_pointer;
			typedef bidirectional_iterator_tag iterator_category;
			typedef bidirectional_iterator self_type;

			bidirectional_iterator(){
				this->element = nullptr;
			}

			bidirectional_iterator(node_pointer element) {
				this->element = element;
			}

			bidirectional_iterator(self_type const &copy) {
				this->element = copy.element;
			}

			bidirectional_iterator &operator = (self_type const &asg) {
				this->element = asg.element;
				return (*this);
			}

			~bidirectional_iterator(){}

			reference operator * () const {
				//return (*element->val); // Cambiado Lunes 26 de Abril 2021 atento a estos cambios. Retomando ft_containers
				return (this->element->val);
			}

			pointer operator -> () const{
				return (&(element->val));
			}

			bool operator == (self_type const &rhs) const {
				if (*this->element != *rhs.element)
					return (false);
				return (true);
			}

			bool operator != (self_type const &rhs) const {
				if (*this == rhs)
					return (false);
				return (true);
			}

			self_type &operator ++ () {
				//this->element = this->element->next();
				if (element && element->next())
					element = element->next();
				return (*this);
			}

			self_type operator ++ (int) {
				self_type tmp(*this);
				//this->element = this->element->next();
				operator++();
				return (tmp);
			}

			self_type &operator -- () {
				//this->element = this->element->prv;
				this->element = this->element->prev();
				return (*this);
			}

			self_type operator -- (int) {
				self_type tmp(*this);
				//this->element = this->element->prv;
				this->element = this->element->prev();
				return (tmp);
			}


		private:
			node_pointer element;
	};

	template <typename T, typename Reference, typename Pointer, typename Distance, typename Node>
	class reverse_bidirectional_iterator
	{
		public:	
			typedef T value_type;
			typedef Reference reference;
			typedef Pointer pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef Node node_pointer;
			typedef bidirectional_iterator_tag iterator_category;
			typedef reverse_bidirectional_iterator self_type;


			reverse_bidirectional_iterator() {
				this->element = nullptr;
			}
			
			reverse_bidirectional_iterator(node_pointer element) {
				this->element = element;
			}

			reverse_bidirectional_iterator(self_type const &copy) {
			
				this->element = copy.element;
			}

			self_type &operator = (self_type const &asg) {
				this->element = asg.element;
				return (*this);
			}

			~reverse_bidirectional_iterator() {};

			reference operator * () {
				return (this->element->val);
			}

			pointer operator -> () {
				return (&(this->element->val));
			}

			bool operator == (self_type const &rhs) const {
				if (*this->element != *rhs.element)
					return (false);
				return (true);
			}

			bool operator != (self_type const &rhs) const {
				if (*this == rhs)
					return (false);
				return (true);
			}

			self_type &operator ++ ()
			{
				this->element = this->element->prev();
				return (*this);
			}

			self_type operator ++ (int)
			{
				self_type tmp(*this);
				this->element = this->element->prev();
				return (tmp);
			}

			self_type &operator -- () {
				this->element = this->element->next();
				return (*this);
			}

			self_type operator -- (int) {
				self_type tmp(*this);
				this->element = this->element->next();
				return (tmp);
			}

		private:
			node_pointer element;
	};
}

#endif
