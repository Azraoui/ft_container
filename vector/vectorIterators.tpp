/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:42:49 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/29 16:46:24 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// // Bismillah allahoma zidna 3ilma


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
