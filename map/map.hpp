#pragma once

#include "./utils/utils.hpp"

namespace ft
{
	template <typename key, typename value, typename Compare = std::less<key>,
	typename Alloc = std::allocator<ft::pair<const key, value> > >
	class map
	{
		// Member types
		public:
			typedef	key				key_type;
			typedef	value			mapped_type;

	};
}