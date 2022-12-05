#ifndef MAP_HPP
#define MAP_HPP

#include "traits_utils.hpp"
#include "traits_utils_pair.hpp"
#include <iostream>

namespace ft {
template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {
		public :

		/*  -------------  Member_types  -----------------------------------*/

		typedef				Key										key_type;
		typedef				T										mapped_value;
		typedef	typename	ft::pair<const Key, T>					value_type;
		typedef				std::size_t								size_type;
		typedef				std::ptrdiff_t							difference_type;
		typedef	typename	Compare									key_compare;
		typedef				Allocator								allocator_type;
		typedef	typename	value_type&								reference;
		typedef	typename	const reference							const_reference;
		typedef	typename	Allocator::pointer						pointer;
		typedef	typename	Allocator::const_pointer				const_pointer;
		typedef	typename	binaryTreeIterator<value_type>			iterator;
		typedef	typename	binaryTreeIterator<const value_type>	const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/*  -------------  Constructors  -----------------------------------*/

		map();
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _mhandle(), _head(NULL), _size(0), _capacity(0), _compAlgo(comp);
		map();
		map();
		~map();

		private :
		allocator_type	_mhandle;
		pointer			_head;
		size_type		_size;
		size_type		_capacity;
		key_compare		_compAlgo;


	};
}

#endif
