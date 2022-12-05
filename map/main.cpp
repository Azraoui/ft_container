#include "./map.hpp"
#include <map>
#include <vector>



int main()
{
	ft::map<int, int> m;
		m.insert(ft::make_pair(9, 42));
		m.insert(ft::make_pair(5, 1337));
		m.insert(ft::make_pair(10, 1337));
		m.insert(ft::make_pair(0, 1337));
		m.insert(ft::make_pair(6, 1337));
		m.insert(ft::make_pair(11, 1337));
		m.insert(ft::make_pair(-1, 1337));
		m.insert(ft::make_pair(1, 1337));
		m.insert(ft::make_pair(2, 1337));
		std::cout << m[99] << std::endl;

		m[99] = 1337;
		ft::map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			std::cout << "key = " << it->first << " value = " << it->second << std::endl;
		}
		// std::map<int, int> 
	return 0;
}