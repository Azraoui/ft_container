#pragma once

#include <iostream>
#include "../srcs/avl.hpp"

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
			Node*	_root;

		public:
			// construct && destruct
			iterator() : _avl(), _node(NULL), _root(NULL) {};
			iterator(Node* node, Node* root) : _avl(), _node(node), _root(root) {};
			iterator(const iterator &x) : _avl(x._avl), _node(x._node), _root(x._root) {}
			~iterator() {};
			iterator	operator = (const iterator &x)
			{
				this->_node = x._node;
				this->_root = x._root;
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
				return (this->_node->data);
			}
			pointer operator -> () {
				return (&this->_node->data);
			}
			const_pointer operator -> () const {
				return (&this->_node->data);
			}
			iterator& operator ++ () {
				_node = _avl.next_node(_root, _node);
				return (*this);
			}
			iterator operator ++ (int) {
				
				iterator _old = *this;
				_node = _avl.next_node(_root, _node);
				return _old;
			}
			iterator& operator -- () {
				if (_node == _avl.minNode(_root) || _node == NULL)
					_node = _avl.maxNode(_root);
				else
					_node = _avl.previous_node(_root, _node);
				return (*this);
			}
			iterator operator -- (int) {
				iterator _old = *this;
				operator--();
				return _old;
			}
	};
}