#pragma once

#include <iostream>
#include "../../sharedUtils/iterator_traits.hpp"

namespace ft
{
	template < class ptr >
	class Random_access_iterator
	{
		public:
			typedef typename ft::Iterator_traits<ptr>::value_type			value_type;
			typedef typename ft::Iterator_traits<ptr>::difference_type		difference_type;
			typedef typename ft::Iterator_traits<ptr>::pointer				pointer;
			typedef typename ft::Iterator_traits<ptr>::reference			reference;
			typedef typename ft::Iterator_traits<ptr>::iterator_category	iterator_category;

		private:
			pointer	__base;

		public:
		// ------------------
			pointer base() const {
				return __base;
			}
		// -----------------
			/**
			 * @brief Default Constructor
			 * A a;
			 */
			Random_access_iterator() : __base(NULL) {
			};
			/**
			 * @brief Paramater Constructor
			 * 
			 */
			Random_access_iterator(pointer p) : __base(p){
			};
			/**
			 * @brief Construct a new Random_access_iterator object
			 * A a(b);
			 * @param obj 
			 */
			Random_access_iterator(Random_access_iterator const &obj){
				*this = obj;
			};
			/**
			 * @brief template copy constructer
			 */
			template <typename T>
			Random_access_iterator(Random_access_iterator<T> const &x)
			{
				__base = x.base();
			}
			/**
			 * @brief overload assigmnet operator
			 * A a = b;
			 * @param obj 
			 * @return Random_access_iterator& 
			 */
			Random_access_iterator & operator = (const Random_access_iterator &obj) {
				this->__base = obj.base();
				return (*this);
			};
			/**
			 * @brief Destroy the Random_access_iterator object
			 * 
			 */
			~Random_access_iterator(){

			};
		// -------------------
			/**
			 * @brief Can be compared for equivalence using the equality/inequality operators
			 * (meaningful when both iterator values iterate over the same underlying sequence).
			 * a == b
			 * a != b
			 */
			bool operator == (const Random_access_iterator &_b) const{
				return this->base() == _b.base();
			};
			bool operator != (const Random_access_iterator &_b) const{
				return this->base() != _b.base();
			};
		// -------------------
			/**
			 * @brief Can be dereferenced as an rvalue (if in a dereferenceable state).
			 * (*a)
			 *  a->m
			 */
			reference	operator * (void) const{
				return *__base;
			}
			pointer	operator -> (void) const{
				return (this->__base);
			}
		// ----------------------
			/**
			 * @brief For mutable iterators (non-constant iterators):
			 * Can be dereferenced as an lvalue (if in a dereferenceable state).
			 * (*a = t)
			 */
			// value_type	operator * (void){
			// 	return *__base;
			// }
		// -----------------------
			/**
			 * @brief Can be incremented (if in a dereferenceable state).
			 * The result is either also dereferenceable or a past-the-end iterator.
			 * Two iterators that compare equal, keep comparing equal after being both increased.
			 *	(++a)
			 *	(a++)
			 *	(*a++)
			 */
			Random_access_iterator & operator ++ () { /* prefix */
				++__base;
				return *this;
			}
			Random_access_iterator operator ++ (int) { /* postfix */
				Random_access_iterator __tmp(*this);
				++(*this);
				return __tmp;
			}
		// -----------------------
			/**
			 * @brief Can be decremented (if a dereferenceable iterator value precedes it).
			 *	(--a)
			 *	(a--)
			 *	(*a--)
			 */
			Random_access_iterator & operator -- () { /* prefix */
				--__base;
				return *this;
			}
			Random_access_iterator operator -- (int) { /* postfix */
				Random_access_iterator __tmp(*this);
				--(*this);
				return __tmp;
			}
		// --------------------------
			/**
			 * @brief Supports the arithmetic operators + and - between an iterator and an integer value,
			 * or subtracting an iterator from another.
			 * a + n
			 * n + a
			 * a - n
			 * a - b
			 */
			Random_access_iterator operator + (difference_type _v) const{
				Random_access_iterator _tmp(*this);
				_tmp += _v;
				return _tmp;
			}
			Random_access_iterator operator - (difference_type _v) const{
				Random_access_iterator _tmp(*this);
				_tmp -= _v;
				return _tmp;
			}
		// ----------------------------
			/**
			 * @brief Can be compared with inequality relational operators (<, >, <= and >=).
			 * a < b
			 * a > b
			 * a <= b
			 * a >= b
			 */
			bool operator < (Random_access_iterator const & _b){
				return (this->base() < _b.base());
			}
			bool operator <= (Random_access_iterator const & _b){
				return (this->base() <= _b.base());
			}
			bool operator > (Random_access_iterator const & _b){
				return (this->base() > _b.base());
			}
			bool operator >= (Random_access_iterator const & _b){
				return (this->base() >= _b.base());
			}
		// ------------------------------
			/**
			 * @brief Supports compound assignment operations += and -=
			 * a += n
			 * a -= n
			 */
			Random_access_iterator operator += (difference_type _v) {
				__base += _v;
				return *this;
			};
			Random_access_iterator operator -= (difference_type _v) {
				__base -= _v;
				return *this;
			};
		
		// -------------------------------
			/**
			 * @brief Supports the offset dereference operator ([])
			 * a[n]
			 */
			reference operator [] (difference_type _p) const{
				return __base[_p];
			}
	};

	// operator+
	template <class Iterator>
	Random_access_iterator<Iterator> operator+ (typename Random_access_iterator<Iterator>::difference_type n, 
	const Random_access_iterator<Iterator>& x) {
		return (x + n);
	};

	// operator-
	template <class Iterator>
	typename Random_access_iterator<Iterator>::difference_type operator- (const Random_access_iterator<Iterator>& lhs,
	const Random_access_iterator<Iterator>& rhs) {
		return (lhs.base() - rhs.base());
	};

}