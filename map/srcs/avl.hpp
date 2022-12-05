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

			Node() { this = NULL; };
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

		public:
			// constructer && destructer
			Avl() : _size(0) {};
			~Avl() {};

			// member function
			size_type	size() const {return this->_size;}
			Node*	new_node(T data) // create new node
			{
				Node *newNode = _nodeAllocator.allocate(1);
				_nodeAllocator.construct(newNode, data);
				return (newNode);
			};
			int		get_height(Node *node)
			{
				if (node == NULL)
					return (0);
				return (node->height);
			}
			int		getBF(Node *node) // get balance factory
			{
				if (node == NULL)
					return (0);
				return (get_height(node->left) - get_height(node->right));
			}
			Node*	leftRotate(Node* node)
			{
				Node*	rightNode = node->right;
				Node*	tmp	= rightNode->left;
			
				rightNode->left = node;
				node->right = tmp;

				node->height = 1 + std::max(get_height(node->left), get_height(node->right));
				rightNode->height = 1 + std::max(get_height(rightNode->left), get_height(rightNode->right));

				return (rightNode);
			}
			Node*	rightRotate(Node* node)
			{
				Node*	leftNode = node->left;
				Node*	tmp	= leftNode->right;
			
				leftNode->right = node;
				node->left = tmp;

				node->height = 1 + std::max(get_height(node->left), get_height(node->right));
				leftNode->height = 1 + std::max(get_height(leftNode->left), get_height(leftNode->right));

				return (leftNode);
			}
			Node*	insert(Node* root, T data) {

				// BST
				if (node == NULL)
				{
					_size += 1;
					return (new_node(data));
				}
				if (_compare(data.first, node->data.first))
					node->left = insert(node->left, data);
				else if (_compare(node->data.first, data.first))
					node->right = insert(node->right, data);
				else
					return node; // If the key is entered

				// update height
				node->height = 1 + (std::max(get_height(node->left), get_height(node->right)));

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
				return (node); // if no change happen;
			};
			Node*	minNode(Node* root)
			{
				if (root->left == NULL)
					return (root);
				return (minNode(root->left));
			}
			Node*	maxNode(Node*	root)
			{
				if (root->right == NULL)
					return (root);
				return (maxNode(root->right));
			}
			Node*	findParent(Node* root, keyType key)
			{
				Node*	parent = NULL;

				while (true)
				{
					if (_compare(key, root->data.first))
					{
						parent = root;
						root = root->left;
					}
					else if (_compare(root->data.first, key))
					{
						parent = root;
						root = root->right;
					}
					else
						return parent;
				}
				return (parent);
			}
			Node*	next_node(Node* root, Node* node)
			{
				Node* parent = findParent(root, node->data.first);
				if (node->right != NULL)
					return minNode(node->right);
				else
				{
					while (parent != NULL)
					{
						if (_compare(node->data.first, parent->data.first))
							break ;
						parent = findParent(root, parent->data.first);
					}
					return parent;
				}
			}
			Node*	previous_node(Node* root, Node* node)
			{
				Node* parent = findParent(root, node->data.first);
				if (node->left != NULL)
					return maxNode(node->left);
				else
				{
					while (parent != NULL)
					{
						if (_compare(parent->data.first, node->data.first))
							break ;
						parent = findParent(root, parent->data.first);
					}
					return parent;
				}
			}
			Node*	delete_node(Node* root, keyType key)
			{
				if (root == NULL)
					return (NULL);
				if (_compare(root->data.first, key))
					root->right = delete_node(root->right, key);
				else if (_compare(key, root->data.first))
					root->left = delete_node(root->left, key);
				else
				{
					if (!root->left || !root->rigth) // if no child or just one child
					{
						Node* tmp = NULL;
						if (root->left)
							tmp = root->left;
						else
							tmp = root->right;
						if (!tmp) // if no child
						{
							_nodeAllocator.destroy(root);
							_nodeAllocator.deallocate(root, 1);
							_size -= 1;
							return ( NULL );
						}
						else
						{
							_nodeAllocator.destroy(root);
							_nodeAllocator.deallocate(root, 1);
							_size -= 1;
							return ( tmp );
						}
					}
					else // with two children
					{
						
					}
				}
			}
	};
}