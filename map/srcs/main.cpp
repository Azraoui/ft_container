#include "avl.hpp"

using namespace ft;


int main()
{
	Node *n;
	avl tree;

	n = NULL;
	n = tree.insert(n, 3);
	n = tree.insert(n, 4);
	n = tree.insert(n, 5);
	n = tree.insert(n, 6);
	n = tree.insert(n, 7);
	std::cout << "key = " << n->key << std::endl;
	std::cout << "height = " << n->height << std::endl;
	return 0;
}