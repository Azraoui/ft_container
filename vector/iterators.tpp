/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:53:31 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 12:39:45 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__ITERATORS_HPP__
# define __ITERATORS_HPP__

// Bismillah allahoma zidna 3ilma


template <class _Tp, class _Allocator> // Return iterator to beginning
typename ft::vector<_Tp, _Allocator>::iterator ft::vector<_Tp, _Allocator>::begin()
{
	return (this->_begin);
}

template <class _Tp, class _Allocator> // Return iterator to end
typename ft::vector<_Tp, _Allocator>::iterator ft::vector<_Tp, _Allocator>::end()
{
	return (this->_end);
}


template <class _Tp, class _Allocator> // Return const_iterator to beginning
typename ft::vector<_Tp, _Allocator>::const_iterator ft::vector<_Tp, _Allocator>::cbegin()
{
	return (this->_begin);
}

template <class _Tp, class _Allocator> // Return const_iterator to end
typename ft::vector<_Tp, _Allocator>::const_iterator ft::vector<_Tp, _Allocator>::cend()
{
	return (this->_end);
}


#endif