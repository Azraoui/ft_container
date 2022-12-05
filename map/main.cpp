#include "./map.hpp"

int main()
{
	ft::map<int, int> m;
		m.insert(ft::make_pair(9, 1337));
		m.insert(ft::make_pair(5, 1337));
		m.insert(ft::make_pair(10, 1337));
		m.insert(ft::make_pair(0, 1337));
		m.insert(ft::make_pair(6, 1337));
		m.insert(ft::make_pair(11, 1337));
		m.insert(ft::make_pair(-1, 1337));
		m.insert(ft::make_pair(1, 1337));
		m.insert(ft::make_pair(2, 1337));
	return 0;
}