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

			private:
				typename	Alloc::template	rebind< Node >::other	_nodeAllocator;

			// constructer && destructer
			Avl() {};
			~Avl() {};

			// member function
			Node*	insert(Node* node, T data) {
				
			};
	};

}