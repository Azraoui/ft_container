#pragma once

#include <iostream>

namespace ft
{
	template <typename T, typename Node, typename Avl>
	class iterator
	{
		public:
			typedef	T								value_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;
			typedef	ptrdiff_t						difference_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;

		private:
			Avl		_avl;
			Node*	_node;

		public:
			// construct && destruct
			iterator() : _avl(), _node(NULL){};
			iterator(const Node* node) : _avl(), _node(node) {};
			~iterator() {};
			iterator	operator = (const iterator &x)
			{
				this->avl = x.avl;
				this->node = x.node;
				return (*this);
			}
			// overload
			
	};
}