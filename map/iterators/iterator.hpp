#pragma once

#include <iostream>

namespace ft
{
	template <typename T, typename Node, typename Avl>
	class iterator // bidirectional_iterator
	{
		public:
			typedef	iterator						iterator_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef	value_type*						pointer;
			typedef const pointer					const_pointer;
			typedef	value_type&						reference;

		public:
			Avl		_avl;
			Node*	_node;

		public:
			// construct && destruct
			iterator() : _avl(), _node(NULL){};
			iterator(const Node* node) : _avl(), _node(node) {};
			~iterator() {};
			iterator	operator = (const iterator &x)
			{
				this->node = x.node;
				return (*this);
			}

			// overload
			bool operator == ( const iterator& x ) {
				return (this->_node == x._node);
			}
			bool operator != ( const iterator& x ) {
				return (this->_node != x._node);
			}
			reference operator * () {
				return (*this->_node->data);
			}
			pointer operator -> () {
				return (this->_node->data);
			}
			const_pointer operator -> () const {
				return (this->_node->data);
			}
	};
}