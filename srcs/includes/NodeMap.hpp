#ifndef NODEMAP_HPP
# define NODEMAP_HPP
# include <iostream>
# include <cstddef>

namespace ft
{
	template <class Pair, class Key>
	struct nodemap
	{
		Pair	*val;
		nodemap	*parent;
		nodemap	*left;
		nodemap	*right;

		nodemap() {
			parent = nullptr;
			left = nullptr;
			right = nullptr;
	};

	nodemap *next()
	{
		nodemap *aux;
		if (right)
		{
			aux = right;
			while (aux->left)
				aux = aux->left;
		}
		else
		{					
			aux = this;
			while (aux->parent && aux == aux->parent->right)
				aux = aux->parent;
				if (aux->parent)
					aux = aux->parent;
		}
		return (aux);
	}


	nodemap *prev()
	{
		nodemap *aux;
		if (left)
		{
			aux = left;
			while (aux->right)
				aux = aux->right;
		}
		else
		{
			aux = this;
			while (aux->parent && aux == aux->parent->left)
				aux = aux->parent;
			if (aux->parent)
				aux = aux->parent;
		}
		return (aux);

	}

	nodemap	*find(nodemap *nd, Key key)
	{
		if (nd == NULL || nd->val->first == key)
			return (nd);
		if (nd->val->first < key)
			return (find(nd->right, key));
		return (find(nd->left, key));
	}
	};
}
#endif
