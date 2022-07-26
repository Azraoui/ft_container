/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:08:41 by ael-azra          #+#    #+#             */
/*   Updated: 2022/07/26 20:30:34 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./iterator.hpp"

template < typename _Tp >
class random_access_iterator : public ft::iterator< _Tp, std::random_access_iterator_tag >
{
	public:
		typedef _Tp									value_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef _Tp*								ptr;
		typedef _Tp&								ref;

	private:
		ptr _base;

	public:
		random_access_iterator();
		random_access_iterator(const random_access_iterator &obj);
		~random_access_iterator();
	
	// 	Overload operators
		random_access_iterator &	operator = (const random_access_iterator &obj);
		bool						operator == (const random_access_iterator &obj);
		bool						operator != (const random_access_iterator &obj);
		value_type					operator * (void) const;
		ptr							operator -> (void) const;
		random_access_iterator &	operator ++ (void);
		random_access_iterator		operator ++ (int);
		random_access_iterator &	operator -- (void);
		random_access_iterator		operator -- (int);
};

#include "iterators.tpp"