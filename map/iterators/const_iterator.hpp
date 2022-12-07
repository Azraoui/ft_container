#pragma once

#include <iostream>
#include "../srcs/avl.hpp"

namespace ft
{
	template <typename T, typename Node, typename Avl>
	class const_iterator // bidirectional_iterator
	{
		public:
			typedef	const_iterator					iterator_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef	const value_type*				pointer;
			typedef	const value_type&				reference;

		public:
			Avl		    _avl;
			const Node*	_node;
			const Node*	_root;

		public:
			// construct && destruct
			const_iterator() : _avl(), _node(NULL), _root(NULL) {};
			const_iterator(const Node* node, const Node* root) : _avl(), _node(node), _root(root) {};
			const_iterator(const const_iterator &x) : _avl(x._avl), _node(x._node), _root(x._root) {};
			~const_iterator() {};
			const_iterator	operator = (const const_iterator &x)
			{
				this->_node = x._node;
				this->_root = x._root;
				return (*this);
			}

			// overload
			bool operator == ( const const_iterator& x ) const{
				return (this->_node == x._node);
			}
			bool operator != ( const const_iterator& x ) {
				return (this->_node != x._node);
			}
			reference operator * () const{
				return (this->_node->data);
			}
			pointer operator -> () const {
				return (&this->_node->data);
			}
			const_iterator& operator ++ () {
				_node = _avl.next_node(_root, _node);
				return (*this);
			}
			const_iterator operator ++ (int) {
				
				const_iterator _old = *this;
				_node = _avl.next_node(_root, _node);
				return _old;
			}
			const_iterator& operator -- () {
				if (_node == _avl.minNode(_root) || _node == NULL)
					_node = _avl.maxNode(_root);
				else
					_node = _avl.previous_node(_root, _node);
				return (*this);
			}
			const_iterator operator -- (int) {
				const_iterator _old = *this;
				operator--();
				return _old;
			}
	};
}