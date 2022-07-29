/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:53:31 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/29 16:43:25 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* start of  random_access_iterator */

template < typename _Tp >
random_access_iterator< _Tp >::random_access_iterator(): _base() {}

template < typename _Tp >
random_access_iterator< _Tp >::random_access_iterator(const random_access_iterator & obj)
{
	*this = obj;
}

template < typename _Tp >
random_access_iterator< _Tp >::~random_access_iterator() {}

// overload operators
template < typename _Tp >
random_access_iterator< _Tp > & random_access_iterator< _Tp>::operator = (const random_access_iterator & obj)
{
	this->_base = obj._base;
	return *this;
}

template < typename _Tp >
bool random_access_iterator< _Tp >::operator == (const random_access_iterator &obj) const
{
	return (this->_base == obj._base);
}

// template < typename _Tp >
// bool random_access_iterator< _Tp >::operator != (const random_access_iterator &obj)
// {
// 	return (this->_base != obj._base);
// }

template < typename _Tp >
typename random_access_iterator< _Tp >::value_type random_access_iterator< _Tp >::operator * (void) const
{
	return (*_base);
}

// template < typename _Tp >
// typename random_access_iterator< _Tp>::ptr random_access_iterator< _Tp>::operator -> (void) const
// {
// 	return (this->_base);
// }

// template < typename _Tp >
// random_access_iterator< _Tp > & random_access_iterator< _Tp >::operator ++ (void)
// {
// 	ptr *tmp = this->_base;
// 	this->base++;
// 	return (*tmp);
// }

// template < typename _Tp >
// random_access_iterator< _Tp > random_access_iterator< _Tp >::operator ++ (int)
// {
// 	this->base++;
// 	return (this);
// }

// template < typename _Tp >
// random_access_iterator< _Tp > & random_access_iterator< _Tp >::operator -- (void)
// {
// 	ptr *tmp = this->_base;
// 	this->base--;
// 	return (*tmp);
// }

// template < typename _Tp >
// random_access_iterator< _Tp > random_access_iterator< _Tp >::operator -- (int)
// {
// 	this->base--;
// 	return (this);
// }

/* end of random_access_iterator */