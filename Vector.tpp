/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:37:44 by ael-azra          #+#    #+#             */
/*   Updated: 2022/04/02 17:37:07 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Building Constructor and ~Destructor

template <typename Type>
ft::Vector<Type>::Vector()
{
	
}

template <typename Type>
ft::Vector<Type>::Vector(Vector const & obj)
{
	*this = obj;
}

template <typename Type>
ft::Vector<Type>::~Vector()
{
	
}


// Building Overloading operators

template <typename Type>
ft::Vector<Type> & ft::Vector<Type>::operator=(Vector const & obj)
{
	// do something here with attributes.
	return *this;
}

// implement member function for Vector Container (My own STL)

