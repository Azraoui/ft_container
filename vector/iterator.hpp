/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:52:20 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 16:06:39 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	template <	typename Category,					// iterator::iterator_category
				typename _Tp,						// iterator::value_type
				typename Distance = ptrdiff_t,		// iterator::difference_type
				typename Pointer = _Tp*,			// iterator::pointer
				typename Reference = _Tp& >			// iterator::reference
	struct iterator
	{
		public:
			typedef _Tp			value_type;
			typedef Category	iterator_category;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
	};
}