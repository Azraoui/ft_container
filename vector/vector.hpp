#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>

namespace ft
{
	template < class _Tp, class _Allocator = std::allocator<_Tp> >
	class vector
	{
		protected:
			typedef	_Allocator				allocator_type;
			typedef	_Tp						value_type;
			typedef	value_type&				reference;
			typedef	const value_type&		const_reference;
			typedef	value_type*				pointer;
			typedef	value_type*				const_pointer;
			typedef	size_t					size_type;

		public:

	};
}

#endif