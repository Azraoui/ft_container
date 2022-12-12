#pragma once

#include "./utils/utils.hpp"
#include "./srcs/avl.hpp"
#include "./iterators/iterator.hpp"
#include "./iterators/const_iterator.hpp"
#include "./iterators/reverse_iterator.hpp"

namespace ft
{
	template <typename key, typename value, typename Compare = std::less<key>,
	typename Alloc = std::allocator<ft::pair<const key, value> > >
	class map
	{
		// Member types
		public:
			typedef				key												key_type;
			typedef				value											mapped_type;
			typedef				ft::pair< const key_type, mapped_type >			value_type;
			typedef				Compare											key_compare;
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef				size_t											size_type;
			typedef				ft::Node< value_type >											_nodeType;
			typedef				ft::Avl<value_type, _nodeType, allocator_type, key_compare>		_avlType;
			typedef				ft::iterator<value_type, _nodeType, _avlType>					iterator;
			typedef				ft::const_iterator<value_type, _nodeType, _avlType>				const_iterator;
			typedef				ft::reverse_iterator<iterator>									reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef	typename	ft::Iterator_traits<iterator>::difference_type					difference_type;

		private:	
			// private variable
			allocator_type	_alloc;
			key_compare		_compare;
			_nodeType*		_root;
			_avlType		_avlTree;

		public:
			// constructor
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :_alloc(alloc), _compare(comp), _root(NULL)
			{}; // empty
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()) :_alloc(alloc), _compare(comp), _root(NULL)
			{ // range
				this->insert(first, last);
			};
			map (const map& x): _root(NULL) // copy
			{
				*this = x;
			};

			// destructor
			~map() {};

			void test() {
				for (int i = 0; i < 100; i++)
				{
					_root = _avlTree.insert(_root, ft::make_pair(i, 10 + i));
				}
				// for (size_t i = 0; i < 10; i++)
				for (iterator it = begin(); it != end(); it++)
				{
					// std::cout << " i = " << i << std::endl;
					std::cout << " it->first = " << it->first << std::endl;
					_root = _avlTree.delete_node(_root, it->first);
					std::cout << "-----------------" << std::endl;
					// _root = _avlTree.insert(_root, ft::make_pair(i, 10 + i));
				}
				std::cout << size() << std::endl;
				// std::cout << _root->data.first << std::endl;
			};

			// copy assigmnet operator
			map& operator= (const map& x) {
				if (size())
					this->clear();
				if (this != &x)
				{
					_alloc = x._alloc;
					_compare = x._compare;
					this->insert(x.begin(), x.end());
				}
				return (*this);
			};

			// Nested class
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};  // constructed with map's comparison object
				public:
					bool operator() (const value_type& x, const value_type& y) const{
						return comp(x.first, y.first);
					}
			};

			// Iterators:
			iterator begin() {
				return iterator(_avlTree.minNode(_root), &_root);
			};
			const_iterator begin() const {
				return const_iterator(_avlTree.minNode(_root), _root);
			};
			iterator end() {
				return iterator(NULL, &_root);
			};
			const_iterator end() const {
				return const_iterator(NULL, _root);
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

			// Element access
			mapped_type& operator[] (const key_type& k) {
				iterator it = find(k);
				if (it != end())
					return (it->second);
				insert(ft::make_pair(k, mapped_type()));
				return (find(k)->second);
			};

			// Modifiers:
			pair<iterator,bool> insert (const value_type& val) { // single element (1)
				iterator it = find(val.first);
				if (it != end())
					return (ft::make_pair(it, false));
				else
				{
					_root = _avlTree.insert(_root, val);
					return (ft::make_pair(find(val.first), true));
				}
			};
			iterator insert (iterator position, const value_type& val) { // with hint (2)
				insert(val);
				iterator it = find(val.first);
				if (it == position)
					return (position);
				return it;
			};
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) { // range (3)
				for (; first != last; first++)
					insert(*first);
			};
			void erase (iterator position) { // (1)
				_root = _avlTree.delete_node(*position._root, position._node->data.first);
			};
			size_type erase (const key_type& k) { // (2)
				size_type __size = size();
				_root = _avlTree.delete_node(_root, k);
				if (__size > size())
					return (1);
				return (0);
			};
			void erase (iterator first, iterator last) { // (3)
				while (first != last)
					erase(first++);
			};
			void swap (map& x) {
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_compare, x._compare);
				std::swap(this->_root, x._root);
				std::swap(this->_avlTree, x._avlTree);
			};
			void clear()
			{
				_avlTree.clear(&_root);
			}

			// capacity
			bool empty() const {
				return (!size());
			};
			size_type size() const {
				return _avlTree.size();
			};
			size_type max_size() const {
				return (std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type >::max()));
			};

			// Observers
			key_compare key_comp() const {
				return _compare;
			};
			value_compare value_comp() const {
				return value_compare(_compare);
			};
			// Operations
			iterator find (const key_type& k) {
				_nodeType*	tmp = _root;
				while (tmp != NULL)
				{
					if (_compare(k, tmp->data.first))
						tmp = tmp->left;
					else if (_compare(tmp->data.first, k))
						tmp = tmp->right;
					else
						return (iterator(tmp, &_root));
				}
				return end();
			};
			const_iterator find (const key_type& k) const {
				_nodeType*	tmp = _root;
				while (tmp != NULL)
				{
					if (_compare(k, tmp->data.first))
						tmp = tmp->left;
					else if (_compare(tmp->data.first, k))
						tmp = tmp->right;
					else
						return (const_iterator(tmp, _root));
				}
				return end();
			};
			size_type count (const key_type& k) const {
				if (find(k) != end())
					return (1);
				return (0);
			};
			iterator lower_bound (const key_type& k) {
				_nodeType*	maxNode = _avlTree.maxNode(_root);
				_nodeType*	minNode = _avlTree.minNode(_root);
				if (_compare(maxNode->data.first, k))
					return end();
				else if (_compare(k, minNode->data.first))
					return (iterator(minNode, &_root));
				else
					return (find(k));
			};
			const_iterator lower_bound (const key_type& k) const {
				_nodeType*	maxNode = _avlTree.maxNode(_root);
				_nodeType*	minNode = _avlTree.minNode(_root);
				if (_compare(maxNode->data.first, k))
					return end();
				else if (_compare(k, minNode->data.first))
					return (const_iterator(minNode, _root));
				else
					return (find(k));
			};
			iterator upper_bound (const key_type& k) {
				_nodeType*	maxNode = _avlTree.maxNode(_root);
				_nodeType*	minNode = _avlTree.minNode(_root);
				if (_compare(maxNode->data.first, k))
					return end();
				else if (_compare(k, minNode->data.first))
					return (iterator(minNode, &_root));
				else
					return (++(find(k)));
			};
			const_iterator upper_bound (const key_type& k) const {
				_nodeType*	maxNode = _avlTree.maxNode(_root);
				_nodeType*	minNode = _avlTree.minNode(_root);
				if (_compare(maxNode->data.first, k))
					return end();
				else if (_compare(k, minNode->data.first))
					return (const_iterator(minNode, _root));
				else
					return (++(find(k)));
			};
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};
			ft::pair<iterator, iterator> equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			// allocator
			allocator_type get_allocator() const {
				return _alloc;
			};
	};
	
	template<class key, class value, class Compare, class Alloc>
	bool operator>= (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return !(lhs < rhs);
	};
	template<class key, class value, class Compare, class Alloc>
	bool operator> (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return (rhs < lhs);
	};
	template<class key, class value, class Compare, class Alloc>
	bool operator<= (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return !(rhs < lhs);
	};
	template<class key, class value, class Compare, class Alloc>
	bool operator<  (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template<class key, class value, class Compare, class Alloc>
	bool operator!= (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return !(lhs == rhs);
	};
	template<class key, class value, class Compare, class Alloc>
	bool operator== (map<key, value, Compare, Alloc> const & lhs, map<key, value, Compare, Alloc> const & rhs) {
		return ( ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()));
	};
}