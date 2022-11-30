#pragma once

#include "../utils/utils.hpp"

namespace ft
{
	// Node
	template< typename T >
	class Node
	{
		public:
			T		data;
			Node	*left;
			Node	*right;
			int		height;

			Node(const T &data): data(data), left(NULL), right(NULL), height(1) {};
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
				Compare												_compare;

			// constructer && destructer
			Avl() : _size(0) {};
			~Avl() {};

			// member function
			Node*	new_node(T data) {
				Node *newNode = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(newNode, data);
				return (newNode);
			};
			int		getHeight(Node *node, Node *n2 = NULL) // return max height or height
			{
				int n2Height = 0;
				if (node == NULL)
					reutrn (0);
				if (n2 != NULL)
					n2Height = n2->height;
				return (std::max(node->height, n2Height));
			}
			int		getBF(Node *node) // get balance factory
			{
				if (node == NULL)
					return (0);
				return (getHeight(node->left) - getHeight(node->right));
			}
			Node*	leftRotate(Node* node)
			{
				Node*	rightNode = node->right;
				Node*	tmp	= rightNode->left;
			
				rightNode->left = node;
				node->right = tmp;

				node->height = 1 + getHeight(node->left, node->right);
				rightNode->height = 1 + getHeight(rightNode->left, rightNode->right);

				return (rightNode);
			}
			Node*	rightRotate(Node* node)
			{
				Node*	leftNode = node->left;
				Node*	tmp	= leftNode->right;
			
				leftNode->right = node;
				node->left = tmp;

				node->height = 1 + getHeight(node->left, node->right);
				leftNode->height = 1 + getHeight(leftNode->left, leftNode->right);

				return (leftNode);
			}
			Node*	insert(Node* node, T data) {

				// BST
				if (node == NULL)
				{
					_size += 1;
					return (newNode(data));
				}
				if (_compare(data.first, node->data.first))
					node->left = insert(node->left, data);
				else if (_compare(node->data.first, data.first))
					node->right = insert(node->right, data);
				else
					return node; // If the key is entered

				// update height
				node->height = 1 + getHeight(node->left, node->right);

				// get balance factory
				int	balanceFactory = getBF(node);

				// Start balancing BST to be AVL
				
				// left left case
				if (balanceFactory > 1 && _compare(data.first, node->left->data.first))
					return (rightRotate(node));
				// left right case
				if (balanceFactory > 1 && _compare(node->left->data.first, data.first))
				{
					node->left = (leftRotate(node->left));
					return (rightRotate(node));
				}
				// right right case
				if (balanceFactory < -1 && _compare(node->right->data.first, data.first))
					return (leftRotate(node));
				// right left case
				if (balanceFactory < -1 && _compare(data.first, node->right->data.first))
				{
					node->right = (rightRotate(node->right));
					return (leftRotate(node));
				}
				return (node) // if no change happen;
			};
	};

}