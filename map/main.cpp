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
			std::cout << "key = " << it->first << " value = " << it->second << std::endl;

		// erase element
		it = m.begin();
		std::cout << "map_size = " << m.size() << std::endl;
		m.erase(it);
		std::cout << "map_size = " << m.size() << std::endl;

		std::cout << "\n------------------------- Test std map ----------------------------" << std::endl;
		std::map<int, int> sm;
		std::map<int, int>::iterator sit;
		sit = sm.end();
		sm.insert(std::make_pair(9, 37));
		sm.insert(std::make_pair(7, 13));
		sm.insert(std::make_pair(10, 13));
		std::cout << "map_size = " << sm.size() << std::endl;
		// sm.erase(sit);
		std::cout << "map_size = " << sm.size() << std::endl;
		std::cout << sm[9] << std::endl;
	return 0;
}