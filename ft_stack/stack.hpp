#pragma once
#include "../ft_vector/vector.hpp"

namespace ft
{
	template <class Type, class Containr = ft::vector<Type> >
	class stack
	{
		public:
			typedef	Type		value_type;
			typedef Containr	container_type;
			typedef	size_t		size_type;
		
		protected:
			container_type _holder;
		

		public:
			explicit stack (const container_type& ctnr = container_type()) : _holder(ctnr) {};
			bool empty() const {return _holder.empty();};
			size_type size() const {return _holder.size();};
			value_type& top() {return _holder.back();};
			const value_type& top() const {return _holder.back();};
			void push (const value_type& val) {_holder.push_back(val);};
			void pop() {_holder.pop_back();};
		private:
				template <class T, class Container>
				friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
				template <class T, class Container>
				friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
				template <class T, class Container>
				friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
				template <class T, class Container>
				friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
				template <class T, class Container>
				friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
				template <class T, class Container>
				friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder == rhs._holder);
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder != rhs._holder);
	};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder < rhs._holder);
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder <= rhs._holder);
	};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder > rhs._holder);
	};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
		return (lhs._holder >= rhs._holder);
	};
}