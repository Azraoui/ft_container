#pragma once

#include <memory> // refernce to allocator
#include <iostream>
#include "./iterator_traits.hpp"
#include "./random_access_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator< T > >
	class vector
	{
		private:
			/* data */

		public:
			typedef 			T												value_type;
			typedef 			Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::Random_access_iterator<pointer>				iterator;
			typedef typename	ft::Iterator_traits<iterator>::difference_type	difference_type;
			typedef 			size_t											size_type;

		// implementation of vector
		public:
			vector(/* args */)
			{
				std::cout << "vector constructor!" << std::endl;
			};
			~vector()
			{
				std::cout << "vector destructor!" << std::endl;
			};
	};
}