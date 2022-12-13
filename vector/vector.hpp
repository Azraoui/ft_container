#pragma once

#include <memory> // refernce to allocator
#include <iostream>
#include <algorithm>
#include "./iterator_traits.hpp"
#include "./random_access_iterator.hpp"
#include "./reverse_iterator.hpp"
#include "./utils.hpp"

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
			typedef	typename	ft::Random_access_iterator<const_pointer>		const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::Iterator_traits<iterator>::difference_type	difference_type;
			typedef 			size_t											size_type;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_buffer;
			allocator_type	_alloc;

		// Member functions
		public:

		// ------------------------------------------
			explicit vector (const allocator_type& alloc = allocator_type()) { // default constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				this->_alloc = alloc;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc){ // fill constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				// need insert here
				insert(begin(), n, val);
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, allocator_type>::type const &alloc = allocator_type()) : _alloc(alloc){ // range constructor
				this->_size = 0;
				this->_capacity = 0;
				this->_buffer = NULL;
				size_type dist = static_cast<size_type>(std::distance(first, last));
				if (dist < 0)
					throw std::length_error("negative distance");
				insert(begin(), first, last);
			};
			vector (const vector& x) : _size(0), _capacity(0), _buffer(NULL){ // copy constructor
				*this = x;
			};
			~vector() {
				clear();
				if (_buffer != NULL && _capacity != 0)
					_alloc.deallocate(_buffer, _capacity);
				_buffer = NULL;
			};
			vector & operator = (const vector & v) {
				assign(v.begin(), v.end());
				return *this;
			}

			// Iterators:
			iterator	begin() {
				return	iterator(_buffer);
			};
			const_iterator begin() const {
				return const_iterator(_buffer);
			};
			iterator	end() {
				return iterator(_buffer + _size);
			};
			const_iterator end() const {
				return const_iterator(_buffer + _size);
			};
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			};
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			};
			reverse_iterator rend() {
				return reverse_iterator(begin());
			};
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
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
			size_type max_size() const {
				return std::min<size_type>(std::numeric_limits<difference_type>::max(), _alloc.max_size());
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
				clear();
				_alloc.deallocate(_buffer, _capacity);
				_buffer = tmp_buffer;
				_size = i;
				_capacity = n;
			};
			void resize (size_type n, value_type val = value_type()) {
				if (n > _capacity)
					reserve(n);
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_buffer + i);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_buffer + i, val);
			};

			// Element access:
			reference operator[] (size_type n){
				return this->_buffer[n];
			}
			const_reference operator[] (size_type n) const{
				return this->_buffer[n];
			}
			reference front() {
				return _buffer[0];
			}
			const_reference front() const{
				return _buffer[0];
			}
			reference back() {
				return _buffer[_size - 1];
			}
			const_reference back() const {
				return _buffer[_size - 1];
			};
			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("index out of range");
				return _buffer[n];
			};
			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("index out of range");
				return _buffer[n];
			};

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
			void push_back(const_reference value) {
				if (!_capacity || _capacity == _size)
					reserve(_capacity > 0 ? (_capacity * 2) : 1);
				_size += 1;
				_alloc.construct(_buffer + _size, value);
			}
			void pop_back()
			{
				if (empty())
					return ;
				_size -= 1;
				_alloc.destroy(_buffer + _size);
			};
			void swap (vector& x) {
				std::swap(_alloc, x._alloc);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_buffer, x._buffer);
			};
			void clear() {
				if (!_buffer)
					return;
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_buffer[i]);
				this->_size = 0;
			}
			iterator insert (iterator position, const value_type& val) { // single element insert
				size_type pos = static_cast<size_type>(std::distance(begin(), position));
				if (pos < 0)
					return position;
				if (!_capacity || _capacity == _size)
					reserve(_capacity > 0 ? (_capacity * 2) : 1);
				for (size_type i = _size - 1; i >= pos && _size > 0; --i)
				{
					_alloc.construct(_buffer + (i + 1), _buffer[i]);
					_alloc.destroy(&_buffer[i]);
				}
				_alloc.construct(_buffer + pos, val);
				_size += 1;
				return (iterator(_buffer + pos));
			};
			void insert (iterator position, size_type n, const value_type& val) { // fill insert
				size_type pos = static_cast<size_type>(std::distance(begin(), position));
				if (pos < 0)
					return ;
				reserve(n + _capacity);
				pointer _tmpBuffer = _alloc.allocate(_size - pos);
				for (size_type i = 0; i < (_size - pos); i++)
					_alloc.construct(&_tmpBuffer[i], _buffer[pos + i]);
				for (size_type i = pos; i < pos + n; i++)
				{
					_alloc.destroy(&_buffer[i]);
					_alloc.construct(&_buffer[i], val);
				}
				_size += n;
				for (size_type i = pos + n; i < _size; i++)
				{
					_alloc.destroy(&_buffer[i]);
					_alloc.construct(&_buffer[i], _tmpBuffer[i - n]);
					_alloc.destroy(&_tmpBuffer[i - n]);
				}
				_alloc.deallocate(_tmpBuffer, _size - n - pos);
			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) { // range insert
				size_type pos = static_cast<size_type>(std::distance(begin(), position));
				if (pos < 0)
					return;
				size_type dist = static_cast<size_type>(std::distance(first, last));
				if (dist < 0)
					return;
				reserve(dist + _capacity);
				pointer _tmpBuffer = _alloc.allocate(_size - pos);
				for (size_type i = 0; i < (_size - pos); i++)
					_alloc.construct(&_tmpBuffer[i], _buffer[pos + i]);
				for (size_type i = pos; i < pos + dist; i++)
				{
					_alloc.destroy(&_buffer[i]);
					_alloc.construct(&_buffer[i], first[i - pos]);
				}
				_size += dist;
				for (size_type i = pos + dist; i < _size; i++)
				{
					_alloc.destroy(&_buffer[i]);
					_alloc.construct(&_buffer[i], _tmpBuffer[i - dist]);
					_alloc.destroy(&_tmpBuffer[i - dist]);
				}
				_alloc.deallocate(_tmpBuffer, _size - dist - pos);
			};

			iterator erase (iterator position) {
				size_type pos = static_cast<size_type>(std::distance(begin(), position));

				_alloc.destroy(&_buffer[pos]);
				_size -= 1;
				for (size_type i = pos; i < _size; i++)
				{
					_alloc.construct(&_buffer[i], _buffer[i + 1]);
					_alloc.destroy(&_buffer[i + 1]);
				}
				return (iterator(_buffer + pos));
			};
			iterator erase (iterator first, iterator last) {
				size_type pos = static_cast<size_type>(std::distance(begin(), first));
				size_type dist = static_cast<size_type>(std::distance(first, last));
				for (size_type i = pos; i < dist + pos; i++)
					_alloc.destroy(&_buffer[i]);
				_size -= dist;
				for (size_type i = pos; i < _size; i++)
				{
					_alloc.construct(&_buffer[i], _buffer[i + 1 + dist]);
					_alloc.destroy(&_buffer[i + 1 + dist]);
				}
				return (iterator(_buffer + pos));
			};

			// Allocator:
			allocator_type get_allocator() const {
				return _alloc;
			};

	}; // end of class;

	// Non-member function overloads

		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
			x.swap(y);
		};

	// relational operators (vector)
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	};
	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	};
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ( ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()));
	};
}