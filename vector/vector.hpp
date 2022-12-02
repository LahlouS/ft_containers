#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include "traits_utils.hpp"
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

	/*  ------------------  MY STANDARD_ITERATOR  -----------------*/
	template <typename T>
	class	standard_tab_iterator : public std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&> {
		public :

		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::pointer pointer;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::difference_type difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::value_type value_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::reference reference;

		/* ---------- Constructors ---------- */

		standard_tab_iterator() : _location(NULL) {  /*  nothing to put for the moment  */  }
		standard_tab_iterator(pointer start_addr) {
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

		standard_tab_iterator<value_type>	operator+(difference_type const & toAdd) const {
			return (standard_tab_iterator<value_type>(this->_location + toAdd));
		}

		standard_tab_iterator<value_type>	operator-(difference_type const & toAdd) const {
			return (standard_tab_iterator<value_type>(this->_location - toAdd));
		}

		difference_type	operator+(standard_tab_iterator<value_type> const & toAdd) {
			return (this->_location + toAdd._location);
		}

		difference_type	operator-(standard_tab_iterator<value_type> const & toAdd) {
			return (this->_location - toAdd._location);
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



		/*  -----------------  MY VECTOR  ---------------------  */
	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public :
			/*  -----------  Member Data type definition  -----------  */
			typedef typename Alloc::value_type							value_type;
			typedef 		 Alloc										allocator_type;
			typedef typename Alloc::reference							reference;
			typedef			 const reference							const_reference;
			typedef typename Alloc::difference_type						difference_type;
			typedef typename Alloc::size_type							size_type;
			typedef typename Alloc::pointer								pointer;
			typedef 		 const pointer								const_pointer;
			typedef 		 standard_tab_iterator<value_type>			iterator;
			typedef 		 standard_tab_iterator<const value_type>	const_iterator;
			typedef			 reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef			 reverse_iterator<iterator>					reverse_iterator;

			/*  -----------  Constructors definition  -----------  */
			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _first_element(NULL), _mhandle(alloc) {  /*  nothing to put for the moment  */  }

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _first_element(NULL), _mhandle(alloc) {
				_first_element = _mhandle.allocate(_size);
				while (--n)
					_mhandle.construct(_first_element + n, val);
				_mhandle.construct(_first_element + n, val);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, typename enable_if< !is_integral<InputIterator>::value, InputIterator>::type = NULL, const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _first_element(NULL), _mhandle(alloc) {
				this->_mhandle = alloc;
				InputIterator temp = first;
				size_t	i = 0;
				while (temp++ != last)
					this->_size++;
				this->_capacity = this->_size;
				_first_element = _mhandle.allocate(_size);
				while (first != last) {
					_mhandle.construct(_first_element + i, *first);
					first++;
					i++;
				}
			}
			vector (const vector& x) : _size(0), _capacity(0), _first_element(NULL), _mhandle(x.get_allocator()){
				*this = x;
			}

			const vector&	operator= (const vector& x){
				this->reserve(x.capacity());
				this->assign(x.begin(), x.end());
				return (*this);
			}

			~vector(){
					for (size_type tmp = this->_size; tmp < this->_size; tmp++)
						_mhandle.destroy(_first_element + tmp);
					_mhandle.deallocate(_first_element, this->_capacity);
			}

			/*  -----------  Overload function    -------------*/

			reference operator[] (size_type n) {
				return (*(this->_first_element + n));
			}

			const_reference operator[] (size_type n) const {
				return (*(this->_first_element + n));
			}

			/*  -----------  Methodes definition  -----------  */

			/*  -----------  capacity functions  ------------  */
			size_type	size() const {
				return (this->_size);
			}

			size_type	capacity() const {
				return (this->_capacity);
			}

			size_type	max_size() const {
				return (_mhandle.max_size());
			}

			void		resize (size_type new_size, value_type val = value_type()) {
				if (new_size >= this->max_size() || new_size < 0)
					throw std::out_of_range("ERREUR: Une erreur a ete detecte entre la chaise et le clavier !");
				if (new_size < this->_size)
					erase(iterator(_first_element + (new_size - 1)), iterator(end()));
				else if (new_size > this->_size)
					insert(end(), (new_size - this->_size), val);
				this->_size = new_size;
			}

			bool empty() const {
				return (this->_size == 0);
			}

			void	reserve(size_type n, bool intern = 0) {
				pointer		dest = NULL;
				if (n > this->_capacity || intern)
				{
					dest = _allocNewTab(n);
					if (dest)
						_swapTab(dest);
				}
				this->_capacity = n;
			}
			// not in c++98 :/
			void shrink_to_fit(void) {
				if (this->_size > 0)
					reserve(this->_size, 1);
			}


			/* ------------ Acess Elements ---------------------*/
			reference at (size_type n) {
				if (n >= 0 && n < this->_size)
					return (*(this->_first_element + n));
				else
					throw std::out_of_range("Halte : l'argument transmis a cette fonction semble 'out-of-range' si je ne m'abuse\n");
			}

			const_reference at (size_type n) const {
				if (n >= 0 && n < this->_size)
					return (*(this->_first_element + n));
				else
					throw std::out_of_range("Halte : l'argument transmis a cette fonction semble 'out-of-range' si je ne m'abuse\n");
			}

			reference front(void){
				return (*(this->_first_element));
			}

			const_reference front() const{
				return (*(this->_first_element));
			}

			reference back() {
				return (*(this->_first_element + (this->_size - 1)));
			}

			const_reference back() const {
				return (*(this->_first_element + (this->_size - 1)));
			}

			pointer data() {
				return (_first_element);
			}

			const_pointer data() const {
				return (_first_element);
			}
			/*  -----------  Modifiers functions  ------------  */

			iterator insert(iterator position, const value_type& val) {
				return (insert(position, 1, val));
			}

			iterator insert(iterator position, size_type n, const value_type& val) {
				size_type	new_capacity = 0;
				pointer		dest = NULL;
				size_type	pos = _findPosition(position);

				if (_capacity != (new_capacity = _increase_capacity(_size + n, _capacity)))
					dest = _allocNewTab(new_capacity);
				if (dest)
					_swapTab(dest);
				_insertVal(val, n, pos);
				_capacity = new_capacity;
				_size += n;
				return (iterator(_first_element + pos));
			}


			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename enable_if< !is_integral<InputIterator>::value, InputIterator>::type = NULL) {
				while (first != last) {
					insert(position, 1, *first);
					first++;
				}
			}

			iterator		erase(iterator position) {
				if (position != this->end() - 1)
					return (erase(position, position + 1));
				else
				{
					_mhandle.destroy(_first_element + (_size - 1));
					_size -= 1;
					return (this->end());
				}
			}

			iterator		erase(iterator first, iterator last) {
				size_type diff = iteratorDifference(first, last);
				pointer		lastOne = this->end().getLocation() - 1;
				for (iterator first_cpy = first;first_cpy != last; first_cpy++) {
					_mhandle.destroy(first_cpy.getLocation());
					if ((first_cpy.getLocation() + diff) < lastOne)
						_mhandle.construct(first.getLocation(), *(first_cpy.getLocation() + diff));
				}
				this->_size -= diff;
				return (first);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type = NULL) {
				this->erase(this->begin(), this->end());
				this->insert(this->end(), first, last);
			}


			void assign (size_type n, const value_type& val) {
				if (this->_size != 0)
					this->erase(this->begin(), this->end());
				this->insert(this->end(), n, val);
			}

			void push_back (const value_type& val) {
				this->insert(this->end(), val);
			}

			void pop_back(void) {
				this->erase(this->end() - 1);
			}

			void swap (vector& x) {
				ft::vector<value_type> temp(this->begin(), this->end());
				this->assign(x.begin(), x.end());
				x.assign(temp.begin(), temp.end());
			}

			void	clear(void) {
				if (this->_size > 0)
					this->erase(this->begin(), this->end());
			}

			/*  -------------  Iterators Functions  -------------*/

			iterator		begin( void ) {
				return (iterator(_first_element));
			}
			const_iterator	begin() const {
				return (const_iterator(_first_element));
			}

			iterator		end( void ) {
				return (iterator(_first_element + _size));
			}

			const_iterator		end( void ) const {
				return (const_iterator(_first_element + _size));
			}

			reverse_iterator		rbegin( void ) {
				return (reverse_iterator(_first_element + _size));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(_first_element + _size));
			}

			reverse_iterator		rend( void ) {
				return (reverse_iterator(_first_element));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(_first_element));
			}

			const_iterator cbegin() const /*noexcept*/ {
				return (const_iterator(_first_element));
			}

			const_iterator cend() const /*noexcept*/ {
				return (const_iterator(_first_element + _size));
			}

			const_reverse_iterator crbegin() const /*noexcept*/ {
				return (const_reverse_iterator(_first_element + _size));
			}

			const_reverse_iterator crend() const /*noexcept*/ {
				return (const_reverse_iterator(_first_element));
			}
			/*  -----------------------  Other  --------------------------*/

			allocator_type get_allocator() const {
				return (this->_mhandle);
			}

			/*  --------------  print function for debbug  -------------  */

			void	print(void) {
				std::cout << "_size : " << _size << BN;
				std::cout << "_capacity : " << _capacity << BN;
				std::cout << "what is inside my vector : " << BN;
				for (size_type i = 0; i < _size; i++)
					std::cout << _first_element[i] << " ";
				std::cout << BN;
			}

		private :

			/*  -------------  private methodes  -------------  */

			size_type _findPosition(iterator position) {
				size_type i = 0;
				for (iterator it = this->begin(); it != this->end() && it != position; it++, i++);
				return (i);
			}

			size_type	_increase_capacity(size_type evaluated_size, size_type _capacity_tmp) {
				if (_capacity_tmp < evaluated_size && _capacity_tmp)
					return (_increase_capacity(evaluated_size, _capacity_tmp * 2));
				if (_capacity_tmp == 0)
					return (_increase_capacity(evaluated_size, (_capacity_tmp + 2) * 2));
				if ( _capacity_tmp >= evaluated_size)
					return (_capacity_tmp);
				return (_capacity_tmp);
			}

			pointer		_allocNewTab(size_type new_capacity) {
				return (_mhandle.allocate(new_capacity));
			}

			void	_copyTab(pointer dest) {
				for (size_type i = 0; i < _size; i++)
					_mhandle.construct(dest + i, _first_element[i]);
			}
			void	_cleanOldTab(void) {
				for (size_type i = 0; i < _size; i++)
					_mhandle.destroy(_first_element + i);
				_mhandle.deallocate(_first_element, _size);
			}
			void	_swapTab(pointer newTab) {
				_copyTab(newTab);
				_cleanOldTab();
				this->_first_element = newTab;
			}

			void	_shiftRight(pointer tab, size_type position, size_type offset) {
				pointer tab_tmp;
				for (tab_tmp = tab + (this->_size - (1 + position)); tab_tmp != tab; tab_tmp--)
				{
					_mhandle.construct(tab_tmp + offset, *tab_tmp);
					_mhandle.destroy(tab_tmp);
				}
					_mhandle.construct(tab_tmp + offset, *tab_tmp);
					_mhandle.destroy(tab_tmp);
			}

			void	_putValue(pointer tab, size_type n, const value_type& val) {
				while (n--)
					_mhandle.construct(tab++, val);
			}

			void	_insertVal(const value_type& val, size_type n, size_type position){
				if (this->_size != 0 && (_first_element + position != _first_element + this->_size))
					_shiftRight(_first_element + position, position, n);
				_putValue(_first_element + position, n, val);
			}


			/*  -------------  private attributes  -------------  */
			private :

			size_type		_size;
			size_type		_capacity;
			pointer 		_first_element;
			allocator_type	_mhandle;

	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typedef typename vector<T, Alloc>::const_iterator iterator;

		return (!(ft::lexicographical_compare<iterator, iterator>(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()))
			&& !(ft::lexicographical_compare<iterator, iterator>(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend())));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typedef typename vector<T, Alloc>::const_iterator iterator;

		if ((ft::lexicographical_compare<iterator, iterator>(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()))
			|| (ft::lexicographical_compare<iterator, iterator>(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend())))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typedef typename vector<T, Alloc>::const_iterator iterator;

		if ((ft::lexicographical_compare<iterator, iterator>(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend())))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typedef typename vector<T, Alloc>::const_iterator iterator;

		if (((ft::lexicographical_compare<iterator, iterator>(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()))) || lhs == rhs)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (!(lhs <= rhs))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (!(lhs < rhs) || (lhs == rhs))
			return (true);
		return (false);
	}

}

#endif
