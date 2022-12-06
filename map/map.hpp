#pragma once

#include "./utils/utils.hpp"
#include "./srcs/avl.hpp"
#include "./iterators/iterator.hpp"

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
			typedef				ptrdiff_t										difference_type; // ned to change it iterator_trait
			typedef				ft::Node< value_type >											_nodeType;
			typedef				ft::Avl<value_type, _nodeType, allocator_type, key_compare>		_avlType;
			typedef				iterator<value_type, _nodeType, _avlType>						iterator;

		private:	
			// private variable
			allocator_type	_alloc;
			key_compare		_compare;
			_nodeType*		_root;
			_avlType		_avlTree;

		public:
			// constructor && destructor
			map(): _root(), _avlTree() {};
			~map() {};

			// Iterators:
			iterator begin() {
				return iterator(_avlTree.minNode(_root), _root);
			};
			iterator end() {
				return iterator(NULL, _root);
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
				iterator it = insert(val);
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
				_root = _avlTree.delete_node(position._root, position._node->data.first);
			};
			size_type erase (const key_type& k) { // (2)
				size_type __size = size();
				_root = _avlTree.delete_node(_root, k);
				if (__size > size())
					return (1);
				return (0);
			};
			void erase (iterator first, iterator last) { // (3)
				iterator tmp(first);
				for (; first != last; first = tmp)
				{
					tmp++;
					erase(first);
				}
			};
			void swap (map& x) {
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_compare, x._compare);
				std::swap(this->_root, x._root);
				std::swap(this->_avlTree, x._avlTree);
				std::swap(this->size(), x.size());
			};
			void clear()
			{
				if (_root == NULL)
					return ;
				clear(_root->left);
				clear(_root->right);
				_avlTree._nodeAllocator.destroy(_root);
				_avlTree._nodeAllocator.deallocate(_root, 1);
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
			// value_compare value_comp() const {
			// 	return value_compare;
			// };

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
						return (iterator(tmp, _root));
				}
				return end();
			};
			// const_iterator find (const key_type& k) const;
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
					return (iterator(minNode, _root));
				else
					return (find(k));
			};
			// const_iterator lower_bound (const key_type& k) const {

			// };
			iterator upper_bound (const key_type& k) {
				_nodeType*	maxNode = _avlTree.maxNode(_root);
				_nodeType*	minNode = _avlTree.minNode(_root);
				if (_compare(maxNode->data.first, k))
					return end();
				else if (_compare(k, minNode->data.first))
					return (iterator(minNode, _root));
				else
					return (++(find(k)));
			};
			// const_iterator upper_bound (const key_type& k) const;
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			ft::pair<iterator, iterator> equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			// allocator
			allocator_type get_allocator() const {
				return _alloc;
			};
	};
}