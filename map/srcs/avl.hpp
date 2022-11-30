#pragma once

#include "../utils/utils.hpp"

namespace ft
{
	// Node
	template< typename T >
	class Node
	{
		public:
			T		t_pair;
			Node	*left;
			Node	*right;
			int		height;

			Node(const T &t_pair): t_pair(t_pair), left(NULL), right(NULL), height(1) {};
			~Node() {};
	};

	// AVL
	template< typename T, typename Node, typename Alloc, typename Compare>
	class Avl
	{
		public:
			// member type
			typedef typename T::first_type					keyType;
			typedef typename T::second_type					valueType;
			typedef 		 size_t 						size_type;

			private:
				typename	Alloc::template	rebind< Node >::other	_nodeAllocator;
				size_type											_size;
				Alloc												_allocator;

			// constructer && destructer
			Avl() : _size(0) {};
			~Avl() {};

			// member function
			Node*	new_node(T data) {
				Node *newNode = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(newNode, data);
				return (newNode);
			};
			Node*	insert(Node* node, T data) {
				if (node == NULL)
				{
					_size += 1;
					return (newNode(data));
				}
			};
	};

}