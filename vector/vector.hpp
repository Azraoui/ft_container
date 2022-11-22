#pragma once

#include <memory> // refernce to allocator
#include <iostream>
#include <algorithm>
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
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) { // Range version
				size_type dist = static_cast<size_type>(std::distance(first, last));
				if (dist < 0)
					throw std::length_error("negative distance");
				if (dist > _capacity)
					reserve(dist);
				else
					clear();
				size_type i = 0;
				for (; i < dist; i++)
					_alloc.construct(_buffer + i, *(first + i));
				_size = i;
			};
			void assign (size_type n, const value_type& val) { // Fill version
				if (n > _capacity)
					reserve(n);
				else
					clear();
				size_type i = 0;
				for (; i < n; i++)
					_alloc.construct(_buffer + i, val);
				_size = i;
			};
			size_type max_size() const {
				return std::min<size_type>(std::numeric_limits<diffrence_type>::max(), _alloc.max_size());
			};
			void reserve (size_type n) {
				if (n <= _capacity)
					return ;
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				pointer tmp_buffer = NULL;
				tmp_buffer = _alloc.allocate(n);
				size_type i = 0;
				for (; i < _size; i++)
					_alloc.construct(&tmp_buffer[i], _buffer[i]);
				_buffer.clear();
				_alloc.deallocate(&_buffer, &_capacity)
				_buffer = tmp_buffer;
				_size = i;
				_capacity = n;
			};
			void push_back(const_reference value) {
				if (!_capacity || _capacity == _size)
					reserve(_capacity > 0 ? (_capacity * 2) : 1);
				_alloc.construct(_buffer + _size, value);
				_size += 1;
			}
			void pop_back() {
				if (empty())
					return ;
				_size -= 1;
				_alloc.distroy(_buffer + _size);
			};
			void swap (vector& x) {
				vector tmp(x);
				x = tmp;
				*this = x;
			};
			void clear() {
				if (!_buffer)
					return;
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_buffer[i]);
				this->_size = 0;
			}
			iterator insert (iterator position, const value_type& val) { // single element insert
				size_type pos = static_cast<size_type>(std::distance(position, begin()));
				if (!_capacity || _capacity == _size)
					reserve(_capacity > 0 ? (_capacity * 2) : 1);
				_size += 1;
				value_type tmpValue;
				for (size_type i = pos; i < _size ; i++)
				{
					tmpValue = _buffer + i;
					_alloc.construct(_buffer + i, val);
					val = tmpValue;
				}
				return (iterator(_buffer + pos));
			};
			void insert (iterator position, size_type n, const value_type& val) { // fill insert

			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) { // range insert

			};

			// Allocator:

		// ------------------------------------------
			explicit vector (const allocator_type& alloc = allocator_type()) { // default constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				this->_alloc(alloc);
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) { // fill constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				this->_alloc(alloc);
				// need insert here
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) { // range constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				this->_alloc(alloc);
			};
			vector (const vector& x) { // copy constructor
				*this = x;
			};
			~vector() {
				delete [] _buffer;
			};
	};
}