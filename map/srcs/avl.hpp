#pragma once

#include "../utils/utils.hpp"

namespace ft
{
	struct Node
	{
		int		key;
		Node	*left;
		Node	*right;
		int		height;
	};

	class avl
	{
		private:

			Node	*_tree;

		public:
		// --------------------------------

			Node*	newNode(int key)
			{
				Node* n = new Node();
				n->height = 1;
				n->left = NULL;
				n->right = NULL;
				n->key = key;
				return (n);
			}
			int		getHeight(Node *node) {
				if (node == NULL)
					return 0;
				return node->height;
			};
			int		getBalance(Node *node)
			{
				if (node == NULL)
					return 0;
				return (getHeight(node->left) - getHeight(node->right));
			}
			Node*	insert(Node *node, int key)
			{
				if (node == NULL)
					return (newNode(key));
				if (key < node->key)
					node->left = insert(node->left, key);
				else if (key > node->key)
					node->right = insert(node->right, key);
				else
					return node;
				node->height = 1 + (std::max(getHeight(node->left), getHeight(node->right)));
				int balance = getBalance(node);

				if (balance > 1 && key < node->left->key) // left left case
				{
					Node *x = node->left;
					Node *y = x->right;


					x->right = node;
					node->left = y;

					node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
					x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
					return x;
				}
				if (balance < 1 && key > node->right->key)
				{
					Node *y = node->right;
					Node *x = y->left;

					y->left = node;
					node->right = x;

					node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
					y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
					return y;
				}

				return node;
			}

		// --------------------------------
			avl () : _tree(NULL) {};
			~avl() {};
	};
}