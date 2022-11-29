#pragma once

#include "./utils/utils.hpp"
#include "./srcs/avl.hpp"

namespace ft
{
	template <typename key, typename value, typename Compare = std::less<key>,
	typename Alloc = std::allocator<ft::pair<const key, value> > >
	class map
	{
		// Member types
		public:
			typedef				key											key_type;
			typedef				value										mapped_type;
			typedef				ft::pair< const key_type, mapped_type >		value_type;
			typedef				Compare										key_compare;
			typedef				Alloc										allocator_type;
			typedef	typename	allocator_type::reference					reference;
			typedef	typename	allocator_type::const_reference				const_reference;
			typedef	typename	allocator_type::pointer						pointer;
			typedef	typename	allocator_type::const_pointer				const_pointer;
			// typedef	typename												iterator;

	};
}