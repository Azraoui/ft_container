#pragma once

#include <iostream>

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		// Member types
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;
		
		// Member variable
		first_type first;
		second_type second;

		// Member functions
		pair() {};
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};
		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		};
	};

	// Non-member function overloads
	template <class T1, class T2>
	bool operator == (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}
	template <class T1, class T2>
	bool operator != (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}
	template <class T1, class T2>
	bool operator <  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}
	template <class T1, class T2>
	bool operator <= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs<lhs));
	}
	template <class T1, class T2>
	bool operator >  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs<lhs);
	}
	template <class T1, class T2>
	bool operator >= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}

	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1,T2>(x,y) );
	};
	
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

	template <class T>
	struct is_integral {static const bool	value = false;};
	template <>
	struct is_integral<bool>{static const bool	value = true;};
	template <>
	struct is_integral<char>{static const bool value = true;};
	template <>
	struct is_integral<char16_t>{static const bool value = true;};
	template <>
	struct is_integral<char32_t>{static const bool value = true;};
	template <>
	struct is_integral<wchar_t>{static const bool value = true;};
	template <>
	struct is_integral<signed char>{static const bool value = true;};
	template <>
	struct is_integral<short int>{static const bool value = true;};
	template <>
	struct is_integral<int>{static const bool value = true;};
	template <>
	struct is_integral<long int>{static const bool value = true;};
	template <>
	struct is_integral<long long int>{static const bool value = true;};
	template <>
	struct is_integral<unsigned char>{static const bool value = true;};
	template <>
	struct is_integral<unsigned short int>{static const bool value = true;};
	template <>
	struct is_integral<unsigned int>{static const bool value = true;};
	template <>
	struct is_integral<unsigned long int>{static const bool value = true;};
	template <>
	struct is_integral<unsigned long long int>{static const bool value = true;};

	template <bool Cond, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T>
	{ 
		typedef T type; 
	};

}