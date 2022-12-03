#ifndef TRAITS_UTILS_HPP
#define TRAITS_UTILS_HPP

#include <iostream>
#include <string>
#include <memory>

namespace ft {

	/*------------  lexicographical_compare---------------*/

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	/*---------------  Iterators_traits  -----------------*/

	template <class Iterator>
	struct iterator_traits {

		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef	typename	Iterator::reference 		reference;
		typedef	typename	Iterator::iterator_category	iterator_category;

	};

	template <class T>
	struct iterator_traits<T*> {

		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	std::ptrdiff_t					difference;
		typedef	std::random_access_iterator_tag	iterator_category;

	};


	template <class T>
	struct iterator_traits<const T*> {

		typedef	const T									value_type;
		typedef	const T*								pointer;
		typedef	const T&								reference;
		typedef	const std::ptrdiff_t					difference;
		typedef	const std::random_access_iterator_tag	iterator_category;

	};

	template <typename iterator>
	class reverse_iterator {
		public :
			/*  --------------  Member types  ---------------*/
			typedef				iterator											iterator_type;
			typedef	typename	ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<iterator>::value_type			value_type;
			typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<iterator>::pointer				pointer;
			typedef	typename	ft::iterator_traits<iterator>::reference			reference;


			reverse_iterator(){  /*   nothing to put for the moment   */  }
			explicit reverse_iterator (iterator_type it) : _base(it) {
				/*   nothing to put for the moment   */
			}
			template <typename Iter>
			reverse_iterator (reverse_iterator<Iter> const & rev_it) {
				this->_base = rev_it._base;
			}
			~reverse_iterator() {   /* nothing to put for the moment  */   }

			iterator_type	base() const {
				return (_base);
			}

			reverse_iterator&	operator++() {
				_base--;
				return (*this);
			}

			reverse_iterator	operator++( int ) {
				reverse_iterator	temp = *this;
				_base--;
				return (temp);
			}

			reverse_iterator &	operator--() {
				_base++;
				return (*this);
			}

			reverse_iterator	operator--( int ) {
				reverse_iterator	temp = *this;
				_base++;
				return (temp);
			}
			/*  -----------  * & -> -----------  */

			reference	operator*( void ) const {
				return (*(_base - 1));
			}

			pointer	operator->( void ) const {
				return (*(_base - 1));
			}

			/*  -----------  + & - -----------  */

			reverse_iterator			operator+ (difference_type n) const {
				return (reverse_iterator(_base - n));
			}

			reverse_iterator			operator-(difference_type n) const {
				return (reverse_iterator(_base + n));
			}

			difference_type	operator+(reverse_iterator const & toAdd) const {
			return (this->base() - toAdd.base());
			}

			difference_type	operator-(reverse_iterator const & toAdd) const {
				return ((this->base()).operator->() - (toAdd.base()).operator->());
			}

			/*  -----------  += && -=  -----------  */

			reverse_iterator&	operator+= (difference_type n) {
				this->_base -= n;
				return (*this);
			}

			reverse_iterator & 	operator-= (difference_type n) {
				this->_base += n;
				return (*this);
			}

			/*  -----------  += && -=  -----------  */

			reference operator[] (difference_type n) const {
				return (*(_base - (n + 1)));
			}

		private :
			iterator_type	_base;
	};

		/*  ----  non member reverse_iterator overloads  ----  */

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) == (rhs.base() - 1));
	}

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) != (rhs.base() - 1));
	}

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) > (rhs.base() - 1));
	}

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) >= (rhs.base() - 1));
	}

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) < (rhs.base() - 1));
	}

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return ((lhs.base() - 1) <= (rhs.base() - 1));
	}
}

#endif
