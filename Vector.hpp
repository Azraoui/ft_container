/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:34:41 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 17:47:31 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>

namespace ft
{
	typedef long long ll;
	template <typename Type, typename Alloc = std::allocator<Type> >
	class Vector
	{
		private:
			Type*	arr;
			ll		capacity;
			ll		length;

		public:
			Vector();
			Vector(Vector const & obj);
			Vector & operator = (Vector const & obj);
			~Vector();
	};
}

#include "./Vector.tpp"