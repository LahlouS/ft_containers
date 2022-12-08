#ifndef MAP_HPP
#define MAP_HPP

#include "traits_utils.hpp"
#include "traits_utils_pair.hpp"
#include <iostream>

#define BN "\n"

#define RED 1
#define BLACK 0

#define LLR 3
#define LRR 6
#define RRR 8
#define RLR 5

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

		void	_rightRotation(node* little, node *big) {
				node* tmp = little->rightChild;
				little->rightChild = big;
				big->leftChild = tmp;
				if (big->leftChild != this->_leaf)
					big->leftChild->parent = big;
				little->parent = big->parent;
				big->parent = little;
				if (big == this->_head)
					this->_head = little;
				if (little->parent && little->parent->leftChild == big)
					little->parent->leftChild = little;
				else if (little->parent)
					little->parent->rightChild = little;
		}

		void	_leftRotation(node* little, node* big) {
			node *tmp = little->leftChild;
			little->leftChild = big;
			big->rightChild = tmp;
			if (big->rightChild != this->_leaf)
				big->rightChild->parent = big;
			little->parent = big->parent;
			big->parent = little;
			if (big == this->_head)
				this->_head = little;
			if (little->parent && little->parent->rightChild == big)
				little->parent->rightChild = little;
			else if (little->parent)
				little->parent->leftChild = little;
		}

		void	_balance(node* child){

			node* parent = _getUp(child);
			node* gParent = _getUp(parent);
			node* unclRight = _getRight(gParent);
			node* unclLeft = _getLeft(gParent);
			node* uncl = (unclRight == parent) ? unclLeft : unclRight;
			if (child == this->_head) {
				child->color = BLACK;
			} else if (child->color == RED && child != this->_head && parent && parent->color == RED) {
				if (uncl && uncl->color == RED) {
					parent->color = BLACK;
					uncl->color = BLACK;
					gParent->color = RED;
				} else if (uncl->color == BLACK) {
					bool	colorTmp = 0;
					short test = ((child == parent->leftChild) * 1) + (parent == gParent->leftChild) * 2 \
								+ ((child == parent->rightChild) * 3) + (parent == gParent->rightChild) * 5;
					switch (test) {
						case LLR :
							std::cout << "CASE : 1\n\n";
							_rightRotation(parent, gParent);
							colorTmp = parent->color;
							parent->color = gParent->color;
							gParent->color = colorTmp;
							break ;
						case RRR :
							std::cout << "CASE : 2 \n\n";
							_leftRotation(parent, gParent);
							colorTmp = parent->color;
							parent->color = gParent->color;
							gParent->color = colorTmp;
							break ;
						case LRR :
							std::cout << "CASE : 3\n\n";
							_rightRotation(child, parent);
							_leftRotation(child, gParent);
							colorTmp = child->color;
							child->color = gParent->color;
							gParent->color = colorTmp;
							break ;
						case RLR :
							std::cout << "CASE : 4\n\n";
							_leftRotation(child, parent);
							_rightRotation(child, gParent);
							colorTmp = child->color;
							child->color = gParent->color;
							gParent->color = colorTmp;
							break ;
						default :
							break ;
					}
				}
			}
		}

		void	_dive(node* current, const_reference data) {
			bool isBiggest = 1;
			if (current->rightChild == this->_leaf && _compAlgo.operator()(current->data->first, data.first)) {
				current->rightChild = _insertNewElement(current, data, RED);
				current = current->rightChild;
				current->right->parent = current;
			}
			else if (current->leftChild == this->_leaf && _compAlgo.operator()(data.first, current->data->first)) {
				isBiggest = 0;
				current->leftChild = _insertNewElement(current, data, RED);
				current = current->leftChild;
			}
			else if (_compAlgo.operator()(current->data->first, data.first)) {
				_dive(current->rightChild, data);
			}
			else if (_compAlgo.operator()(data.first, current->data->first)) {
				_dive(current->leftChild, data);
			}
			else
				return ;
			_balance(current);
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
				printBT( prefix + (isLeft ? "│   " : "    "), nude->rightChild, true);
				printBT( prefix + (isLeft ? "│   " : "    "), nude->leftChild, false);
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

			node*	_getUp(node *from){
				if (from && from->parent)
					return (from->parent);
				return (NULL);
			}

			node*	_getRight(node *from){
				if (from && from->rightChild)
					return (from->rightChild);
				return (NULL);
			}

			node*	_getLeft(node *from){
				if (from && from->leftChild)
					return (from->leftChild);
				return (NULL);
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
