#pragma once

#include "./iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class Reverse_iterator
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
			Reverse_iterator() : __base_it() {};
			/**
			 * @brief initialization constructor
			 * Constructs a reverse iterator from some original iterator it.
			 * The behavior of the constructed object replicates the original,
			 * except that it iterates through its pointed elements in the reverse order.
			 */
			explicit Reverse_iterator (iterator_type it) : __base_it(it) {};
			/**
			 * @brief  copy / type-cast constructor
			 * Constructs a reverse iterator from some other reverse iterator.
			 * The constructed object keeps the same sense of iteration as rev_it.
			 */
			template <class Iter>
			Reverse_iterator (const Reverse_iterator<Iter>& rev_it) : __base_it(rev_it.__base_it) {};
			/**
			 * @brief Destructor
			 */
			~Reverse_iterator() {};

			// ---------------------------------------------------

			iterator_type base() const {
				return (this->__base_it);
			};
			reference operator*() const {
				iterator_type tmp = __base_it;
				tmp--;
				return (*tmp);
			};
			Reverse_iterator operator+ (difference_type n) const {
				return (Reverse_iterator(__base_it - n));
			};
			Reverse_iterator& operator++() {
				__base_it--;
				return (*this);
			};
			Reverse_iterator operator++(int) {
  				Reverse_iterator temp = *this;
  				++(*this);
 	 			return temp;
			}
			Reverse_iterator& operator+= (difference_type n) {
				__base_it -= n;
				return (*this);
			};
			Reverse_iterator operator- (difference_type n) const {
				return (Reverse_iterator(__base_it + n));
			};
			Reverse_iterator& operator--() {
				__base_it++;
				return (*this);
			};
			Reverse_iterator operator--(int) {
  				Reverse_iterator temp = *this;
  				--(*this);
  				return temp;
			};
			Reverse_iterator& operator-= (difference_type n) {
				__base_it += n;
				return (*this);
			};
			pointer operator->() const {
				return (&operator*());
			};
			reference operator[] (difference_type n) const {
				return (base()[-n-1]);
			};
	}; // End of Reverse_iterator

	// relational operators (Reverse_iterator)
	template <class Iterator>
	bool operator== (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	};
	template <class Iterator>
	bool operator!= (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	};
	template <class Iterator>
	bool operator<  (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	};
	template <class Iterator>
	bool operator>  (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	};
	template <class Iterator>
	bool operator<=  (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	};
	template <class Iterator>
	bool operator>=  (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	};
	// operator+
	template <class Iterator>
	Reverse_iterator<Iterator> operator+ (typename Reverse_iterator<Iterator>::difference_type n, 
	const Reverse_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	};

	// operator-
	template <class Iterator>
	typename Reverse_iterator<Iterator>::difference_type operator- (const Reverse_iterator<Iterator>& lhs,
	const Reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	};
}