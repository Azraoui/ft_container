/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:34:41 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 16:51:51 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	template <typename Type>
	class Vector
	{
		public:
			Vector();
			Vector(Vector const & obj);
			Vector & operator = (Vector const & obj);
			~Vector();
	};
}

#include "./Vector.tpp"