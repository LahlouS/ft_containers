#ifndef TRAITS_UTILS_HPP
#define TRAITS_UTILS_HPP

#include <iostream>
#include <string>
#include <memory>

namespace ft {

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
			typedef				iterator										iterator_type;
			typedef	typename	ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<iterator>::value_type			value_type;
			typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<iterator>::pointer				pointer;
			typedef	typename	ft::iterator_traits<iterator>::reference			reference;


			reverse_iterator(){  /*   nothing to put for the moment   */  }
			explicit reverse_iterator (iterator_type it) : _base(it--) {
				/*   nothing to put for the moment   */
			}
			template <typename Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) {
				this->_base = rev_it._base;
			}
			~reverse_iterator() {   /* nothing tu put for the moment  */   }

			iterator_type	base() {
				return (_base++);
			}

			reverse_iterator<iterator>	const & operator++() {
				_base--;
				return (*this);
			}

			reverse_iterator<iterator>	operator++( int ) {
				reverse_iterator<iterator>	temp = *this;
				_base--;
				return (temp);
			}

			reverse_iterator<iterator>	const & operator--() {
				_base++;
				return (*this);
			}

			reverse_iterator<iterator>	operator--( int ) {
				reverse_iterator<iterator>	temp = *this;
				_base++;
				return (temp);
			}
			/*  -----------  * & -> -----------  */

			reference	operator*( void ) const {
				return (*_base);
			}

			pointer	operator->( void ) const {
				return (*_base);
			};

			/*  -----------  + & - -----------  */

			reverse_iterator<iterator> operator+(difference_type n) const {
				return (reverse_iterator<iterator>(_base - n));
			}

			reverse_iterator<iterator>	operator-(difference_type n) const {
				return (reverse_iterator<iterator>(_base + n));
			}

			/*  -----------  += && -=  -----------  */

			reverse_iterator<iterator> & operator+= (difference_type n) {
				this->_base -= n;
				return (*this);
			}

			reverse_iterator<iterator> & operator-= (difference_type n) {
				this->_base += n;
				return (*this);
			}

		private :
			iterator_type	_base;


	};

}

#endif
