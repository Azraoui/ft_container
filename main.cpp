/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:23:36 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 14:56:15 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int>::iterator iter;

int main()
{
vector<int> g1;
  
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end: ";
	for (iter i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";
  
	return 0;
}