/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:53:31 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 17:26:26 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* start of  input_iterator */

template < typename _Tp >
input_iterator< _Tp >::input_iterator() {}

template < typename _Tp >
input_iterator< _Tp >::input_iterator(const input_iterator & obj)
{
	*this = obj;
}

template < typename _Tp >
input_iterator< _Tp >::~input_iterator() {}

// overload operators
template < typename _Tp >
input_iterator< _Tp > & input_iterator< _Tp>::operator = (const input_iterator & obj)
{
	std::cout << "i was here" << std::endl;
	(void)obj;
	return *this;
}

/* end of input_iterator */


// #ifndef	__ITERATORS_HPP__
// # define __ITERATORS_HPP__

// // Bismillah allahoma zidna 3ilma


// template <class _Tp, class _Allocator> // Return iterator to beginning
// typename ft::vector<_Tp, _Allocator>::iterator ft::vector<_Tp, _Allocator>::begin()
// {
// 	return (this->_begin);
// }

// template <class _Tp, class _Allocator> // Return iterator to end
// typename ft::vector<_Tp, _Allocator>::iterator ft::vector<_Tp, _Allocator>::end()
// {
// 	return (this->_end);
// }


// template <class _Tp, class _Allocator> // Return const_iterator to beginning
// typename ft::vector<_Tp, _Allocator>::const_iterator ft::vector<_Tp, _Allocator>::cbegin()
// {
// 	return (this->_begin);
// }

// template <class _Tp, class _Allocator> // Return const_iterator to end
// typename ft::vector<_Tp, _Allocator>::const_iterator ft::vector<_Tp, _Allocator>::cend()
// {
// 	return (this->_end);
// }


// #endif