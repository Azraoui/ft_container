#pragma once

#include "../utils/utils.hpp"

namespace ft
{
	template< typename T >
	class Node
	{
		public:
			T		value;
			Node	*left;
			Node	*right;
			int		height;

			Node(const T &value): value(value), left(NULL), right(NULL), height(1) {};
			~Node() {};
	};

	// class avl
	// {
	// 	private:

	// 		Node	*_tree;

	// 	public:
	// 	// --------------------------------

	// 		Node*	newNode(int key)
	// 		{
	// 			Node* n = new Node();
	// 			n->height = 1;
	// 			n->left = NULL;
	// 			n->right = NULL;
	// 			n->key = key;
	// 			return (n);
	// 		}
	// 		int		getHeight(Node *node) {
	// 			if (node == NULL)
	// 				return 0;
	// 			return node->height;
	// 		};
	// 		int		getBalance(Node *node)
	// 		{
	// 			if (node == NULL)
	// 				return 0;
	// 			return (getHeight(node->left) - getHeight(node->right));
	// 		}
	// 		Node*	rightRotate(Node* n)
	// 		{
	// 			Node *x = n->left;
	// 			Node *y = x->right;

	// 			x->right = n;
	// 			n->left = y;

	// 			n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
	// 			x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
	// 			return x;
	// 		}
	// 		Node*	leftRotate(Node* n)
	// 		{
	// 			Node *y = n->right;
	// 			Node *x = y->left;

	// 			y->left = n;
	// 			n->right = x;

	// 			n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
	// 			y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
	// 			return y;
	// 		}
	// 		Node*	insert(Node *node, int key)
	// 		{
	// 			if (node == NULL)
	// 				return (newNode(key));
	// 			if (key < node->key)
	// 				node->left = insert(node->left, key);
	// 			else if (key > node->key)
	// 				node->right = insert(node->right, key);
	// 			else
	// 				return node;
	// 			node->height = 1 + (std::max(getHeight(node->left), getHeight(node->right)));
	// 			int balance = getBalance(node);

	// 			if (balance > 1 && key < node->left->key) // left left case
	// 				return rightRotate(node);
	// 			if (balance < -1 && key > node->right->key) // right right case
	// 				return leftRotate(node);
	// 			if (balance > 1 && key > node->left->key) // left right case
	// 			{
	// 				node->left = leftRotate(node->left);
	// 				return rightRotate(node);
	// 			}
	// 			if (balance < -1 && key < node->right->key) // right left case
	// 			{
	// 				node->right = rightRotate(node->right);
	// 				return leftRotate(node);
	// 			}

	// 			return node;
	// 		}

	// 	// --------------------------------
	// 		avl () : _tree(NULL) {};
	// 		~avl() {};
	// };
}