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
/*---------------  remove_cv  -----------------*/
	template< class T > struct remove_cv                   { typedef T type; };
	template< class T > struct remove_cv<const T>          { typedef T type; };
	template< class T > struct remove_cv<volatile T>       { typedef T type; };
	template< class T > struct remove_cv<const volatile T> { typedef T type; };

	template< class T > struct remove_const                { typedef T type; };
	template< class T > struct remove_const<const T>       { typedef T type; };

	template< class T > struct remove_volatile             { typedef T type; };
	template< class T > struct remove_volatile<volatile T> { typedef T type; };


	/*---------------  Enable_if  -----------------*/
	template<bool condition, typename T>
	struct enable_if { /* no type defined SFINAE will do the job*/ };

	template <typename T>
	struct enable_if<true, T> { typedef T type; /*  "returning a type meaning there is a match "*/ };

	/*---------------  Is_Integral  -----------------*/

	template<typename T>
	struct is_int {
		static const bool value = false;
	};

	template<>
	struct is_int<bool> {
		static const bool value = true;
	};
	template<>
	struct is_int<char> {
		static const bool value = true;
	};
	template<>
	struct is_int<wchar_t> {
		static const bool value = true;
	};
	template<>
	struct is_int<signed char> {
		static const bool value = true;
	};
	template<>
	struct is_int<short int> {
		static const bool value = true;
	};

	template<>
	struct is_int<int> {
		static const bool value = true;
	};

	template<>
	struct is_int<long int> {
		static const bool value = true;
	};

	template<>
	struct is_int<long long int> {
		static const bool value = true;
	};
	template<>
	struct is_int<unsigned char> {
		static const bool value = true;
	};
	template<>
	struct is_int<unsigned short int> {
		static const bool value = true;
	};
	template<>
	struct is_int<unsigned int> {
		static const bool value = true;
	};
	template<>
	struct is_int<unsigned long int> {
		static const bool value = true;
	};
	template<>
	struct is_int<unsigned long long int> {
		static const bool value = true;
	};

	template<typename T>
	struct is_integral {
		static const bool value = is_int<typename remove_cv<T>::type >::value;
	};

	/*--------------  Iterator_difference  ---------*/

	template <typename T_iterator>
	typename ft::iterator_traits<T_iterator>::difference_type	iteratorDifference(T_iterator first, T_iterator last) {
		return (compute_diffence(first, last, typename ft::iterator_traits<T_iterator>::iterator_category()));
	}

	template <typename T_iterator>
	typename ft::iterator_traits<T_iterator>::difference			iteratorDifference(T_iterator first, T_iterator last) {
		return (last - first);
	}

	template <typename T_iterator>
	typename ft::iterator_traits<T_iterator>::difference_type	compute_diffence(T_iterator first, T_iterator last, std::random_access_iterator_tag) {
		return (last - first);
	}

	template <typename T_iterator>
	typename ft::iterator_traits<T_iterator>::difference_type	compute_diffence(T_iterator first, T_iterator last, std::bidirectional_iterator_tag) {
		size_t	i = 0;
		while (first != last){
			first++;
			i++;
		}
		return (i);
	}

	template <typename T_iterator>
	typename ft::iterator_traits<T_iterator>::difference_type	compute_diffence(T_iterator first, T_iterator last, std::input_iterator_tag) {
		size_t	i = 0;
		while (first != last){
			first++;
			i++;
		}
		return (i);
	}

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
			reverse_iterator(reverse_iterator<Iter> const & rev_it) {
				this->_base = rev_it.base();
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

			// reference	operator*( void ) const {
				// return (*(_base - 1));
			// }
//
			// pointer	operator->( void ) const {
				// return ((_base - 1).operator->());
			// }

			reference	operator*( void ) const {
				iterator_type temp = this->_base;
				temp--;
				return (*(temp));
			}

			pointer	operator->( void ) const {
				iterator_type temp = this->_base;
				temp--;
				return (temp.operator->());
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
				return ((this->base() - toAdd.base()) * - 1);
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

	template <typename T>
	reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> const & rhs) {
		return (rhs + n);
	}

		/*  ----  non member reverse_iterator overloads  ----  */

	template <class Iterator1, class Iterator2>
	bool	operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l == tmp_r);
	}

	template <class Iterator1, class Iterator2>
	bool	operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l != tmp_r);
	}

	template <class Iterator1, class Iterator2>
	bool	operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l > tmp_r);
	}

	template <class Iterator1, class Iterator2>
	bool	operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l >= tmp_r);
	}

	template <class Iterator1, class Iterator2>
	bool	operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l < tmp_r);
	}

	template <class Iterator1, class Iterator2>
	bool	operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		Iterator1 tmp_l = lhs.base();
		Iterator2 tmp_r = rhs.base();
		tmp_l--;
		tmp_r--;
		return (tmp_l <= tmp_r);
	}




	// template <class Iterator1, class Iterator2>
	// bool	operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) == (rhs.base() - 1));
	// }
//
	// template <class Iterator1, class Iterator2>
	// bool	operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) != (rhs.base() - 1));
	// }
//
	// template <class Iterator1, class Iterator2>
	// bool	operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) > (rhs.base() - 1));
	// }
//
	// template <class Iterator1, class Iterator2>
	// bool	operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) >= (rhs.base() - 1));
	// }
//
	// template <class Iterator1, class Iterator2>
	// bool	operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) < (rhs.base() - 1));
	// }
//
	// template <class Iterator1, class Iterator2>
	// bool	operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		// return ((lhs.base() - 1) <= (rhs.base() - 1));
	// }
}

#endif
