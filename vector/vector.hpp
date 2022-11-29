#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#define BN "\n"

namespace ft {

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


template <typename T>
class	standard_tab_iterator : public std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&> {
	public :

		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::pointer pointer;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::difference_type difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::value_type value_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::reference reference;

		/* ---------- Constructors ---------- */

		standard_tab_iterator() : _location(NULL) {  /*  nothing to put for the moment  */  }
		standard_tab_iterator(T* start_addr) {
			_location = start_addr;
		}
		standard_tab_iterator(standard_tab_iterator<T> const & itToCopy) {
			*this = itToCopy;
		}

		standard_tab_iterator<T> const & operator=(standard_tab_iterator<T> const & itToAssign) {
			this->_location = itToAssign._location;
			return (*this);
		}

		~standard_tab_iterator(){ /*  nothing to put for the moment  */ }

		/* ---------- Operators overloads ---------- */
		/*  -----------  ++ ++ && -- -- -----------  */

		standard_tab_iterator<T> const & operator++( void ){
			_location++;
			return (*this);
		}

		standard_tab_iterator<T>	operator++( int ) {
			standard_tab_iterator<T>	temp = *this;
			_location++;
			return (temp);
		}

		standard_tab_iterator<T> const & operator--( void ){
			_location--;
			return (*this);
		}

		standard_tab_iterator<T>	operator--( int ) {
			standard_tab_iterator<T>	temp = *this;
			_location--;
			return (temp);
		}
		/*  -----------  == && != -----------  */

		bool		operator==(standard_tab_iterator<T> const & itToComp) {
			if (_location == itToComp._location)
				return (true);
			return (false);
		}

		bool		operator!=(standard_tab_iterator<T> const & itToComp) {
			if (_location != itToComp._location)
				return (true);
			return (false);
		}

		/*  -----------  * && -> -----------  */

		reference	operator*( void ) const {
			return (*_location);
		}

		pointer	operator->( void ) const {
			return (*_location);
		};

		/*  -----------  + && - -----------  */

		standard_tab_iterator<value_type>	operator+(difference_type const & toAdd) {
			return (standard_tab_iterator<value_type>(this->_location + toAdd));
		}

		standard_tab_iterator<value_type>	operator-(difference_type const & toAdd) {
			return (standard_tab_iterator<value_type>(this->_location - toAdd));
		}

		/*  -----------  += && -=  -----------  */

		standard_tab_iterator<T> const & operator+=(difference_type const & toAddAssign) {
			this->_location += toAddAssign;
			return (*this);
		}

		standard_tab_iterator<T> const & operator-=(difference_type const & toAddAssign) {
			this->_location -= toAddAssign;
			return (*this);
		}

		pointer	getLocation(void) {
			return (_location);
		}
	private :
		/*  --------------  private attribute  ----------------  */
		pointer	_location;

};

template <typename T, typename Alloc = std::allocator<T> >
class vector {
	public :
			/*  -----------  Member Data type definition  -----------  */
			typedef typename Alloc::value_type						value_type;
			typedef 		 Alloc									allocator_type;
			typedef typename Alloc::reference						reference;
			typedef			 const reference						const_reference;
			typedef typename Alloc::difference_type					difference_type;
			typedef typename Alloc::size_type						size_type;
			typedef typename Alloc::pointer							pointer;
			typedef 		 const pointer							const_pointer;

			typedef 		 standard_tab_iterator<T>			iterator;
			typedef 		 standard_tab_iterator<const T>		const_iterator;

//			typedef			 reverse_iterator<iterator>			reverse_iterator;
//			typedef			 reverse_iterator<const_iterator>	const_reverse_iterator;

			/*  -----------  Constructors definition  -----------  */
			explicit vector(const allocator_type& alloc = allocator_type()) : size(0), capacity(0), first_element(NULL), mhandle(alloc) {  /*  nothing to put for the moment  */  }

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : size(n), capacity(n), first_element(NULL), mhandle(alloc) {
				first_element = mhandle.allocate(size);
				while (--n)
					mhandle.construct(first_element + n, val);
				mhandle.construct(first_element + n, val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, typename enable_if< !is_integral<InputIterator>::value, InputIterator>::type = NULL, const allocator_type& alloc = allocator_type())
			: size(0), capacity(0), first_element(NULL), mhandle(alloc) {
				this->mhandle = alloc;
				InputIterator temp = first;
				size_t	i = 0;
				while (temp++ != last)
					this->size++;
				this->capacity = this->size;
				first_element = mhandle.allocate(size);
				while (first != last) {
					mhandle.construct(first_element + i, *first);
					first++;
					i++;
				}
			}

			~vector(){
				for (size_type tmp = this->size; tmp < this->size; tmp++)
					mhandle.destroy(first_element + tmp);
				mhandle.deallocate(first_element, this->capacity);

			}
			/*  -----------  Methodes definition  -----------  */

			iterator insert(iterator position, const value_type& val) {
				size_type	new_capacity = 0;
				pointer		dest = NULL;
				size_type	pos = _findPosition(position);

				if (capacity != (new_capacity = _increase_capacity(size + 1, capacity)))
					dest = _allocNewTab(new_capacity);
				if (dest)
					_swapTab(dest);
				_insertVal(val, 1, pos);
				capacity = new_capacity;
				size += 1;
				return (iterator(first_element + pos));
			}

			void insert(iterator position, size_type n, const value_type& val);


			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);


//			iterator		erase(iterator position);

			iterator		begin( void ) {
				return iterator(first_element);
			}

			iterator		end( void ) {
				return (iterator(first_element + size));
			}

			/*  --------------  print function for debbug  -------------  */

			void	print(void) {
				std::cout << "size : " << size << BN;
				std::cout << "capacity : " << capacity << BN;
				std::cout << "what is inside my vector : " << BN;
				for (size_type i = 0; i < size; i++)
					std::cout << first_element[i] << " ";
				std::cout << BN;
			}

	private :

			/*  -------------  private methodes  -------------  */

			size_type _findPosition(iterator position) {
				size_type i = 0;
				for (iterator it = this->begin(); it != this->end() && it != position; it++, i++);
				return (i);
			}

			size_type	_increase_capacity(size_type evaluated_size, size_type capacity_tmp) {
				if (capacity_tmp < evaluated_size && capacity_tmp)
					return (_increase_capacity(evaluated_size, capacity_tmp * 2));
				if (capacity_tmp == 0)
					return (_increase_capacity(evaluated_size, (capacity_tmp + 2) * 2));
				if ( capacity_tmp >= evaluated_size)
					return (capacity_tmp);
				return (capacity_tmp);
			}

			pointer		_allocNewTab(size_type new_capacity) {
				return (mhandle.allocate(new_capacity));
			}

			void	_copyTab(pointer dest) {
				for (size_type i = 0; i < size; i++)
					mhandle.construct(dest + i, first_element[i]);
			}
			void	_cleanOldTab(void) {
				for (size_type i = 0; i < size; i++) {
					mhandle.destroy(first_element + i);
				}
				mhandle.deallocate(first_element, size);
			}
			void	_swapTab(pointer newTab) {
				_copyTab(newTab);
				_cleanOldTab();
				first_element = newTab;
			}

			void	_shiftValue(pointer tab, size_t position, size_type offset) {
				pointer tab_tmp;
				for (tab_tmp = tab + (this->size - (1 + position)); tab_tmp != tab; tab_tmp--) {
					*(tab_tmp + offset) = *tab_tmp;
				}
				if (tab != (this->first_element + this->size))
					*(tab_tmp + offset) = *tab_tmp;
			}

			void	_putValue(pointer tab, size_type n, const value_type& val) {
				while (n--)
					mhandle.construct(tab++, val);
			}

			void	_insertVal(const value_type& val, size_type n, size_type position){
				if (this->size != 0 && (first_element + position != first_element + this->size))
					_shiftValue(first_element + position, position, n);
				_putValue(first_element + position, n, val);
			}


			/*  -------------  private attributes  -------------  */
			private :

			size_type		size;
			size_type		capacity;
			pointer 		first_element;
			allocator_type	mhandle;

};

}
#endif
