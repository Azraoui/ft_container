#pragma once

#include "./pair.hpp"

namespace ft
{

	// equal
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ) {
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first2++;
			first1++;
		}
		return (true);
	};

	// lexicographical_compare
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ) {
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			else if (*first1 > *first2)
				return false;
			first2++;
			first1++;
		}
		return (first2 != last2);
	};

	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1,T2>(x,y) );
	};
}