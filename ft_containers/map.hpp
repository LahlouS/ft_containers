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

		typedef struct node {

		node(){}
		node(ft::pair<const key, T> new_data, node* p, node* r, node* l) : this->data(new_data), parent(p), rightChild(r), leftChild(l) {}
		~node();
		ft::pair<const key, T> data;
		node*	parent;
		node*	rightChild;
		node*	leftChild;

		} node;

		/*  -------------  Constructors  -----------------------------------*/

		map() : _head(NULL), _size(0), _capacity(0),  {}
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _head(NULL), _size(0), _capacity(0), _compAlgo(comp);
		~map() {  /*  nothing to put for the moment  */  }

		bool	_bst_insert(node *current_node, reference new_data) {
			if (!currentNode->rightChild && !current_node->leftChild)
				_newNode(currentNode, new_data);
			else if (_compAlgo(currentNode, new_data))
				bst_insert(currentNode->rightChild, new_data);
			else
				bst_insert(current_node->left, newdata);
		}

		void	_newNode(currentNode, new_data) {
			new _node;
		}

		private :
			allocator_type	_mhandle;
			node			_head;
			size_type		_size;
			size_type		_capacity;
			key_compare		_compAlgo;


	};
}

#endif
