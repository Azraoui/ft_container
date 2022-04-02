/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:33:54 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 14:38:31 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

namespace ft
{
	template <class DataType, class Container = vector<DataType> >
	class Stack
	{
		protected:
			DataType *Data;

		public:
			// 
			Stack();
			Stack(Stack const & obj);
			Stack & operator = (Stack const & obj);
			~Stack();
	};
	template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	  return (lhs.data == rhs.data)
  }
}