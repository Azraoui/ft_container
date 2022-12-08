#pragma once

#include "./srcs/avl.hpp"
#include "./iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator 
	{
		public:
			typedef				Iterator											iterator_type;
			typedef	typename	ft::Iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename	ft::Iterator_traits<Iterator>::value_type			value_type;
			typedef	typename	ft::Iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename	ft::Iterator_traits<Iterator>::pointer				pointer;
			typedef	typename	ft::Iterator_traits<Iterator>::reference			reference;
		
		private:
			iterator_type	__base_it;

		public:
			// Member functions

			/**
			 * @brief Default constructor
			 * 	Constructs a reverse iterator that points to no object.
			 * The internal base iterator is value-initialized.
			 */
			reverse_iterator() : __base_it() {};
			/**
			 * @brief initialization constructor
			 * Constructs a reverse iterator from some original iterator it.
			 * The behavior of the constructed object replicates the original,
			 * except that it iterates through its pointed elements in the reverse order.
			 */
			explicit reverse_iterator (iterator_type it) : __base_it(it) {};
			/**
			 * @brief  copy / type-cast constructor
			 * Constructs a reverse iterator from some other reverse iterator.
			 * The constructed object keeps the same sense of iteration as rev_it.
			 */
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : __base_it(rev_it.__base_it) {};
			/**
			 * @brief Destructor
			 */
			~reverse_iterator() {};

			// ---------------------------------------------------

			iterator_type base() const {
				return (this->__base_it)
			};
			reference operator*() const {
				iterator_type tmp = __base_it;
				tmp--;
				return (*tmp);
			};
			reverse_iterator operator+ (difference_type n) const {
				__base_it -= n;
				return (reverse_iterator(__base_it));
			};
			reverse_iterator& operator++() {
				__base_it--;
				return (*this);
			};
			reverse_iterator  operator++(int) {
				reverse_iterator tmp(__base_it);
				__base_it--;
				return (tmp);
			};
			reverse_iterator operator- (difference_type n) const {
				__base_it += n;
				return (reverse_iterator(__base_it));
			};
	};
}