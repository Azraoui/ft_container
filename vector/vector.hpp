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

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_buffer;
			allocator_type	_alloc;

		// Member functions
		public:
			// Iterators:
			iterator	begin() {
				return	iterator(_buffer);
			};
			iterator	end() {
				return iterator(_buffer + _size);
			};

			// Capacity:
			size_type	capacity() const{
				return this->_capacity;
			};
			size_type	size() const{
				return this->_size;
			};
			bool	empty() const{
				if (!_size)
					return true;
				return false;
			};

			// Element access:
			vector & operator = (const vector & v) {
				delete [] _buffer;
				_size = v.size();
				_capacity = v.capacity();
				_buffer = new value_type[_size];
				for (size_type i = 0; i < _size; i++)
					_buffer[i] = v[i];
				return *this;
			}
			reference operator[] (size_type n){
				return this->_buffer[n];
			}
			const_reference operator[] (size_type n) const{
				return this->_buffer[n];
			}
			reference front() {
				return buffer[0];
			}
			reference back() {
				return buffer[_size - 1];
			}

			// Modifiers:
			void push_back(const reference value) {

			}
			void clear(){
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
			}

			// Allocator:

		// ------------------------------------------
			explicit vector (const allocator_type& alloc = allocator_type()) { // default constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
			}
			~vector() {
				delete [] _buffer;
			};
	};
}