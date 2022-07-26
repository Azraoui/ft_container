/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:53:39 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 20:27:29 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include "iterators.hpp"

namespace ft
{
	template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
	class vector
	{
		public:

			// Member types
			typedef				_Allocator						allocator_type;
			typedef	typename	allocator_type::value_type		value_type;
			typedef	typename	allocator_type::size_type		size_type;
			typedef	typename	allocator_type::reference		reference;
			typedef	typename	allocator_type::const_reference	const_reference;
			typedef	typename	allocator_type::pointer			pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			typedef				random_access_iterator< _Tp >	iterator;
			typedef				const_pointer					const_iterator;

		protected: 							// private attributes
			pointer				_begin;
			pointer				_end;

		public:
			// constructor and destructor:
			vector();
			~vector();
			vector & operator = (const vector &obj);

			// Member functions:
			
			//	* Iterators:
			// iterator		begin(); // Return iterator to beginning
			// iterator		end(); // Return iterator to end
			// const_iterator	cbegin(); // Return const_iterator to beginning
			// const_iterator	cend(); // Return const_iterator to end
	};
}

#endif