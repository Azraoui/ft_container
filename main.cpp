/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:23:36 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 14:25:44 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Stack.hpp"
#include <iostream>
#include <string.h>

char*	fs(void)
{
	char *s;
	s = strdup("kdjjfkdjfk");
	return s;
}
void a()
{
	fs();
}
int main()
{
	a();
	system("leaks a.out");	
	return 0;
}