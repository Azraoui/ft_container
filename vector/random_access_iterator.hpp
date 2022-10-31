#pragma once

#include <iostream>
#include "./iterator_traits.hpp"

namespace ft
{
	template < class ptr >
	class Random_access_iterator
	{
		public:
			typedef typename ft::Iterator_traits<ptr>::value_type			value_type;
			typedef typename ft::Iterator_traits<ptr>::difference_type		difference_type;
			typedef typename ft::Iterator_traits<ptr>::pointer				pointer;
			typedef typename ft::Iterator_traits<ptr>::reference			reference;
			typedef typename ft::Iterator_traits<ptr>::iterator_category	iterator_category;

		private:
			pointer	arry;

		public:
			Random_access_iterator(/* args */)
			{
				
			};
			~Random_access_iterator()
			{
				
			};
	};	
}