#pragma once
#include <memory> // refernce to allocator
#include <iostream>

namespace ft
{
	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
		private:
			/* data */

		public:
			typedef T value_type;
			typedef typename Alloc<T> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef size_t size_type

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