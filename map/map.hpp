#pragma once

#include "./utils/utils.hpp"
#include "./srcs/avl.hpp"

namespace ft
{
	template <typename key, typename value, typename Compare = std::less<key>,
	typename Alloc = std::allocator<ft::pair<const key, value> > >
	class map
	{
		// Member types
		public:
			typedef				key											key_type;
			typedef				value										mapped_type;
			typedef				ft::pair< const key_type, mapped_type >		value_type;
			typedef				Compare										key_compare;
			typedef				Alloc										allocator_type;
			typedef	typename	allocator_type::reference					reference;
			typedef	typename	allocator_type::const_reference				const_reference;
			typedef	typename	allocator_type::pointer						pointer;
			typedef	typename	allocator_type::const_pointer				const_pointer;
			typedef				size_t										size_type;
			typedef				ptrdiff_t									difference_type; // ned to change it iterator_trait
			// typedef	typename												iterator;

		private:
			// private member types
			typedef	ft::Node< value_type >										_nodeType;
			typedef	ft::Avl<value_type, _nodeType, allocator_type, key_compare>	_avlType;
			
			// private variable
			allocator_type	_alloc;
			_nodeType*		_root;
			_avlType		_avlTree;

		public:
			// constructor && destructor
			map(): _root(NULL) {};
			~map() {};
			void	insert(void)
			{
					_root = _avlTree.insert(_root, ft::make_pair(9, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(5, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(10, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(0, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(6, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(11, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(-1, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(1, 1337));
					_root = _avlTree.insert(_root, ft::make_pair(2, 1337));
				
				std::cout << _avlTree.get_height(_root) << std::endl;
				std::cout << "size = " << size() << std::endl;
				if (empty())
					std::cout << "map empty" << std::endl;
				else
					std::cout << "may not empty" << std::endl;
				std::cout << "max_size = " << max_size() << std::endl;
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
	};
}