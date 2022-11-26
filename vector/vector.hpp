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
	struct is_integral {
		static const bool value = false;
	};
	template<>
	struct is_integral<bool> {
		static const bool value = true;
	};
	template<>
	struct is_integral<char> {
		static const bool value = true;
	};
	template<>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};
	template<>
	struct is_integral<signed char> {
		static const bool value = true;
	};
	template<>
	struct is_integral<short int> {
		static const bool value = true;
	};
		template<>
	struct is_integral<int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<long int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<long long int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned short int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned long int> {
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned long long int> {
		static const bool value = true;
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
		/* ---------- Constructors ---------- */

		standard_tab_iterator() : location(NULL) {  /*  nothing to put for the moment  */  }
		standard_tab_iterator(T* start_addr) {
			location = start_addr;
		}
		standard_tab_iterator(standard_tab_iterator<T> const & itToCopy) {
			*this = itToCopy;
		}

		standard_tab_iterator<T> const & operator=(standard_tab_iterator<T> const & itToAssign) {
			this->location = itToAssign.location;
			return (*this);
		}

		~standard_tab_iterator(){ /*  nothing to put for the moment  */ }

		/* ---------- Operators overloads ---------- */


		standard_tab_iterator<T> const & operator++( void ){
			location++;
			return (location);
		}

		standard_tab_iterator<T>	operator++( int ) {
			standard_tab_iterator<T>	temp = *this;
			location++;
			return (temp);
		}

		standard_tab_iterator<T> const & operator--( void ){
			location--;
			return (location);
		}

		standard_tab_iterator<T>	operator--( int ) {
			standard_tab_iterator<T>	temp = *this;
			location--;
			return (temp);
		}

		bool		operator==(standard_tab_iterator<T> const & itToComp) {
			if (location == itToComp.location)
				return (true);
			return (false);
		}

		bool		operator!=(standard_tab_iterator<T> const & itToComp) {
			if (location != itToComp.location)
				return (true);
			return (false);
		}

		T const &	operator*( void ) {
			return (*location);
		}

		T const &	operator->( void ) {
			return (*location);
		};


	private :
		pointer	location;
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
			void			insert(iterator position, size_type n, const value_type & val);
//			iterator		erase(iterator position);

			iterator		begin( void ) {
				return iterator(first_element);
			}

			iterator		end( void ) {
				return (iterator(first_element + size));
			}
	private :
			size_type		size;
			size_type		capacity;
			pointer 		first_element;
			allocator_type	mhandle;
};
}


#endif


