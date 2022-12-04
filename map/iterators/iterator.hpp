#pragma once

#include <iostream>

namespace ft
{
	template <typename T, typename Node, typename Avl>
	class iterator
	{
		public:
			typedef	T								value_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;
			typedef	ptrdiff_t						difference_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;

		private:
			Avl		avl;
			Node*	node;

		public:
			// construct && destruct
			iterator(/* args */) {

			};
			~iterator() {

			};
			iterator	operator = (const iterator &x)
			{
				this->avl = x.avl;
				this->node = x.node;
				return (*this);
			}
			// overload

	};
}