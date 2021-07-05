#ifndef NODE_HPP
# define NODE_HPP
# include <cstddef>

namespace ft {
	template <typename T>
	class node
	{
		public:
			typedef T value_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef node self_type;
			
			value_type val;
			/*Cambia el tipo a node si te da algun problema.*/
			node *nxt;
			node *prv;
		public:
			node(const value_type &val = value_type()) {
				this->nxt = nullptr;
				this->prv = nullptr;
				this->val = val;
			}

			node (const node &copy) {
				this->nxt = copy.nxt;
				this->prv = copy.prv;
				this->val = copy.val;
			}

			self_type &operator = (const self_type &asg) {
				this->nxt = asg.nxt;
				this->prv = asg.prv;
				this->val = asg.val;
				return (*this);
			}

			~node() {};
			
			/*Tienes que comprobar que se supone que hacen estos comparadores. lo hacen a nivel profundo o solo se comparan los objetos...*/
			/*
			bool operator == (const self_type &rhs) const {
				if (nxt == rhs.nxt && prv == rhs.prv && val == rhs.val)
					return (true);
				return (false);
			}

			bool operator != (const self_type &rhs) const {
				if (*this != rhs)
					return (true);
				return (false);
			}*/

			bool operator==(const self_type &other)
			{
				if (this->val != other.val)
					return (false);
				if (this->nxt != other.nxt)
					return (false);
				if (this->prv != other.prv)
					return (false);
				return (true);
			}

			bool operator!=(const self_type &other)
			{
				return (!(*this == other));
			}

			self_type *next() {
				return (nxt);
			}

			self_type *prev() {
				return (prv);
			}
	};
}
#endif
