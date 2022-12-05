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

			// Modifiers:
			void	insert(void)
			{
					insert(ft::make_pair(9, 1337));
					insert(ft::make_pair(5, 1337));
					insert(ft::make_pair(10, 1337));
					insert(ft::make_pair(0, 1337));
					insert(ft::make_pair(6, 1337));
					insert(ft::make_pair(11, 1337));
					insert(ft::make_pair(-1, 1337));
					insert(ft::make_pair(1, 1337));
					insert(ft::make_pair(2, 1337));

				_nodeType* nnode = _avlTree.minNode(_root);
				while (nnode != NULL)
				{
					std::cout << nnode->data.first << std::endl;
					nnode = _avlTree.next_node(_root, nnode);
				}
				_root = _avlTree.delete_node(_root, 6);
				_nodeType* node = _avlTree.minNode(_root);
				while (node != NULL)
				{
					std::cout << node->data.first << std::endl;
					node = _avlTree.next_node(_root, node);
				}
			} // end of test insert
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
			// void erase (iterator position) { // (1)
				
			// };
			// size_type erase (const key_type& k) { // (2)

			// };
			// void erase (iterator first, iterator last) { // (3)

			// };

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

			// allocator
			allocator_type get_allocator() const {
				return _alloc;
			};
	};
}