/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:46:04 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/29 16:48:50 by ael-azra         ###   ########.fr       */
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
	std::vector<int>::iterator it2 = v.end() - 1;
	
	// int *a = new int[3];
	// int *b = a; 

	// std::cout << "a = " << a << std::endl;
	// if (a == b)
	// 	std::cout << "Yes" << std::endl;
	// else
	// 	std::cout << "No" << std::endl;
		
	std::cout << "\n*****************\n";
	
	if (it == it2)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	
	std::cout << *it2 << " " << *it <<  std::endl;

	std::cout << "\nTest My Vector\n";
	
	// ft::vector<int>::iterator i2;
	// ft::vector<int>::iterator i4;
	// // ft::vector<int>::iterator i2;
	// if (i4 == i2)
	// 	std::cout << "Yes" << std::endl;
	// else
	// 	std::cout << "No" << std::endl;
	
	// std::cout << *i4 << " " << *i2 <<  std::endl;
	
	return 0;
}