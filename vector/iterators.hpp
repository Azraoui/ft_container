/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:08:41 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 17:47:50 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./iterator.hpp"

template < typename _Tp >
class input_iterator : public ft::iterator< std::input_iterator_tag, _Tp >
{
	public:
		input_iterator();
		input_iterator(const input_iterator &obj);
		~input_iterator();
	
	// overload operators
		input_iterator &	operator = (const input_iterator &obj);
		// bool				operator == (const input_iterator &obj);
		// bool				operator != (const input_iterator &obj);
		// reference			operator * (void) const;
		// pointer				operator -> (void) const;
		// input_iterator &	operator ++ (void);
		// input_iterator		operator ++(int) (void);
		
};

// template < typename _Tp >
// class random_access_iterator : public ft::iterator< _Tp, std::random_access_iterator_tag >
// {
	
// };

// template < typename _Tp >
// class random_access_iterator : public ft::iterator< _Tp, std::random_access_iterator_tag >
// {
	
// };

// template < typename _Tp >
// class random_access_iterator : public ft::iterator< _Tp, std::random_access_iterator_tag >
// {
	
// };

// template < typename _Tp >
// class random_access_iterator : public ft::iterator< _Tp, std::random_access_iterator_tag >
// {
	
// };

#include "iterators.tpp"