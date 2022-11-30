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
			typedef typename T::first_type	first_type;
			typedef typename T::second_type	second_type;
	};

}