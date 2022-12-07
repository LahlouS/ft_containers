#ifndef MAP_HPP
#define MAP_HPP

#include "traits_utils.hpp"
#include "traits_utils_pair.hpp"
#include <iostream>

#define BN "\n"

#define RED 1
#define BLACK 0

namespace ft {
template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public :

		/*  -------------  Member_types  -----------------------------------*/

		typedef				Key										key_type;
		typedef				T										mapped_value;
		typedef	typename	ft::pair<const Key, T>					value_type;
		typedef				std::size_t								size_type;
		typedef				std::ptrdiff_t							difference_type;
		typedef				Compare									key_compare;
		typedef				Allocator								allocator_type;
		typedef				value_type&								reference;
		typedef				const value_type&						const_reference;
		typedef	typename	Allocator::pointer						pointer;
		typedef	typename	Allocator::const_pointer				const_pointer;
		// typedef	typename	binaryTreeIterator<value_type>			iterator;
		// typedef	typename	binaryTreeIterator<const value_type>	const_iterator;
		// typedef	typename	ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef	typename	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef struct node {

		node() : color(BLACK), data(NULL), parent(NULL), rightChild(NULL), leftChild(NULL){	}
		node(map::pointer new_data, node* p, node* r, node* l, bool c) : color(c), data(new_data), parent(p), rightChild(r), leftChild(l) {	}
		~node() {}

		bool	color;
		pointer data;
		node*	parent;
		node*	rightChild;
		node*	leftChild;

		} node;

		/*  -------------  Constructors  -----------------------------------*/

		map() : _head(NULL), _size(0), _capacity(0) {
			_leaf = new node;
			_head = _leaf;
		}

		explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _head(NULL), _size(0), _capacity(0), _compAlgo(comp), _mhandle(alloc) {
			_leaf = new node;
			_head = _leaf;
		}

		~map() {
			std::cout << "Default ~map destructor called\n\n";
			this->_freeTree(this->_head);
			delete _leaf;
		}

		node*	_insertNewElement(node *parent, const_reference data, bool color) {
			pointer temp = _mhandle.allocate(1);
			node*	tempNode;
			_mhandle.construct(temp, data);
			tempNode = new node(temp, parent, this->_leaf, this->_leaf, color);
			return (tempNode);
		}

		void	insert(const_reference new_data) {
			if (this->_head != _leaf)
				this->_dive(_head, new_data);
			else
				this->_head = _insertNewElement(NULL, new_data, BLACK);
		}

		void	_dive(node* current, const_reference data) {
			bool way = _compAlgo.operator()(current->data->first, data.first);
			if (current->rightChild == this->_leaf && way) {
				current->rightChild = _insertNewElement(current, data, RED);
			}
			else if (current->leftChild == this->_leaf && !way) {
				current->leftChild = _insertNewElement(current, data, RED);
			}
			else if (way)
			{
				_dive(current->rightChild, data);
			}
			else if (!way)
				_dive(current->leftChild, data);
		}

		void printBT(const std::string& prefix, const node* nude, bool isLeft)
		{
			if(nude != NULL)
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				if (nude != this->_leaf)
					std::cout << "(" << nude->data->first << ")" << (nude->color ? "R" : "B" ) << std::endl;
				else
					std::cout << " #" << std::endl;
				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), nude->leftChild, true);
				printBT( prefix + (isLeft ? "│   " : "    "), nude->rightChild, false);
			}
		}

		void printBT()
		{
			printBT("", this->_head, false);
		}

		private :
		/*  ------------- private functions  ---------------*/
			void	_freeTree(node *current){
				if (current == _leaf)
					return ;
				_freeTree(current->rightChild);
				_freeTree(current->leftChild);
				_mhandle.destroy(current->data);
				_mhandle.deallocate(current->data, 1);
				delete current;
			}
		/*  ------------- private attributes  ---------------*/
			allocator_type	_mhandle;
			node*			_head;
			node*			_leaf;
			size_type		_size;
			size_type		_capacity;
			key_compare		_compAlgo;


	};
}

#endif
