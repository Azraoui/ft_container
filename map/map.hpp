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
					_root = _avlTree.insert(_root, ft::make_pair(9, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(5, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(10, 42));
					_root = _avlTree.insert(_root, ft::make_pair(0, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(6, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(11, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(-1, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(1, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(2, 1337));
				
				// std::cout << _avlTree.get_height(_root) << std::endl;
				// std::cout << "size = " << size() << std::endl;
				// if (empty())
				// 	std::cout << "map empty" << std::endl;
				// else
				// 	std::cout << "may not empty" << std::endl;
				// std::cout << "max_size = " << max_size() << std::endl;

				// ------------------------------------------

				// _nodeType*	parent = _avlTree.findParent(_root,9);
				// std::cout << parent->data.first << std::endl;
				// _nodeType* node = _avlTree.maxNode(_root);
				// while (node != NULL)
				// {
				// 	std::cout << node->data.first << std::endl;
				// 	node = _avlTree.previous_node(_root, node);
				// }
				// iterator it = end();
				// it--;
				// for (; true; it--)
				// {
				// 	std::cout << it->first << " value = " << it->second << std::endl;
				// 	if (it == begin())
				// 		break;
				// }
				// _nodeType* nnode = _avlTree.minNode(_root);
				// while (nnode != NULL)
				// {
				// 	std::cout << nnode->data.first << std::endl;
				// 	nnode = _avlTree.next_node(_root, nnode);
				// }

				iterator it = find(-1);
				if (it != end())
					std::cout << it->first << " value = " << it->second << std::endl;
			}
			// pair<iterator,bool> insert (const value_type& val) { // single element (1)
				
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