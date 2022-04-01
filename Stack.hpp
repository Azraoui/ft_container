/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:33:54 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/01 11:44:32 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

template <class DataType, class Container = vector<DataType> >
class Stack
{
	protected:
		DataType *Data;

	public:
		typedef DataType* iterator;
		Stack();
		Stack(Stack const & obj);
		Stack & operator = (Stack const & obj);
		~Stack();
};