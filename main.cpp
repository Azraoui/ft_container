/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:46:04 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 18:12:26 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include <set>
#include "./vector/vector.hpp"

int main()
{
	// ft::vector<int>::iterator it;
	// ft::vector<int>::iterator it1(it);
	// // ft::vector<int> v;
	// int *p;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator it2 = v.end();

	// before
	std::cout << *v.begin() << std::endl;
	std::cout << *v.end() << std::endl;
	
	std::cout << "\n--------------\n";
	// after
	it = it2;
	std::cout << *it << std::endl;
	std::cout << *it2 << std::endl;
	
	return 0;
}