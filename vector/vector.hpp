#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>

namespace ft {

template <typename T>
class	standard_tab_iterator : public std::iterator<std::random_access_iterator_tag, T, ptrdiff_t, T*, T&> {
	public :

		/* ---------- Constructors ---------- */

		standard_tab_iterator() : location(NULL) {  /*  nothing to put for the moment  */  }
		standard_tab_iterator(pointer const & start_addr) : location(start_addr) {  /*  nothing to put for the moment  */  }
		standard_tab_iterator(standard_tab_iterator<T> & itToCopy) {
			*this = itToCopy;
		}

		standard_tab_iterator<T> const & operator=(standard_tab_iterator<T> & itToAssign) {
			this->location = itToAssign->location;
			return (this->location);
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
			if (location == itToCopy.getLocation())
				return (true);
			return (false);
		}

		bool		operator!=(standard_tab_iterator<T> const & itToComp) {
			if (location != itToCopy.getLocation())
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
			typedef typename Alloc::value_type					value_type;
			typedef 		 Alloc								allocator_type;
			typedef typename Alloc::reference					reference;
			typedef			 const reference					const_reference;
			typedef typename Alloc::difference_type				difference_type;
			typedef typename Alloc::size_type					size_type;
			typedef typename Alloc::pointer						pointer;
			typedef			 const pointer						const_pointer;

			typedef 		 standard_tab_iterator<T>			iterator;
			typedef 		 standard_tab_iterator<const T>		const_iterator;

//			typedef			 reverse_iterator<iterator>			reverse_iterator;
//			typedef			 reverse_iterator<const_iterator>	const_reverse_iterator;

			/*  -----------  Constructors definition  -----------  */
			explicit vector(const allocator_type& alloc = allocator_type()) : size(0), capacity(0), pointer(NULL), mhandle(alloc) {  /*  nothing to put for the moment  */  }
			explicit vector(size_type n, const value_type& = value_type(), const allocator_type& alloc = allocator_type()) : size(n), capacity(n), pointer(NULL), mhandle(alloc) {
				pointer = mhandle.allocate(size);
				
			}


			/*  -----------  Methodes definition  -----------  */
//			void			insert(iterator position, size_type n, const value_type & val);
//			iterator		erase(iterator position);

			iterator		begin();
			iterator		end();
	private :
			pointer 		first_element;
			size_type		size;
			size_type		capacity;
			allocator_type	mhandle;
};

}


#endif


