#ifndef MAP_HPP
#define MAP_HPP

#include "traits_utils.hpp"
#include "traits_utils_pair.hpp"
#include <cstdlib>
#include <iostream>

#define BN "\n"

#define RED 1
#define BLACK 0

#define LLR 3
#define LRR 6
#define RRR 8
#define RLR 5

#define SIBLING_IS_L 16
#define SIBLING_IS_R 1
#define SIBLING_IS_RED 2
#define NEPHEW_R_IS_RED 4
#define NEPHEW_L_IS_RED 8

namespace ft {


	/*  ------------------ MY_MAP --------------------  */
	template <typename T>
	class	binary_tree_iterator;

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
			typedef				binary_tree_iterator<value_type>		iterator;
			typedef				binary_tree_iterator<const value_type>	const_iterator;
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
				if (this->_head != this->_leaf)
					this->_freeTree(this->_head);
				delete _leaf;
			}

			size_type	size() const {
				return (this->_size);
			}
			// ft::pair<iterator,bool> insert (const value_type& val) {
			void	insert (const value_type& val) {
				node*	ret = NULL;
				bool	isbigger = 1;
				bool	isOk	 = 1;
				if (this->_head != _leaf)
					ret = this->_dive(_head, val, isbigger, isOk);
				else
					ret = this->_head = _insertNewElement(NULL, val, BLACK);
				if (isOk)
					this->_size += 1;
				//std::cout << "---> key : " << ret->data->first << " isBigger" << isbigger << " isOk " << isOk << BN;
				// return (ft::make_pair<>)
			}

			/* ------------------  Iterators stuff  ---------------------- */

			iterator		begin() {
				if (this->size()) {
					return (iterator(this->_findLowestVal(this->_head), this->_leaf));
				}
				return (iterator());
			}

			const_iterator	begin() const {
				if (this->size()) {
					return (const_iterator(this->_findLowestVal(this->_head), this->_leaf));
				}
				return (const_iterator());
			}

			iterator		end() {
				return (iterator(this->_leaf, this->_leaf));
			}
			void	erase(const value_type& val) {
				node*	rm			= _search(this->_head, val);//_dive(_head, val, isbigger, isOk);
				node*	substitute	= NULL;

				if (this->_head == this->_leaf || !this->_size)
					return ;
				if (rm) {
					substitute = _find_subsitute(rm);
					node *legacy = _transplant(rm, substitute);
					if (substitute->color == BLACK && legacy->color == BLACK && substitute != this->_head) // meaning double black shit
						_fixDoubleBlack(legacy, substitute->parent);
					else
						legacy->color = BLACK;
					if (substitute == this->_head)
						this->_head = this->_leaf;
					delete substitute;
					this->_size -= 1;
					this->_leaf->parent = _findBiggestVal(this->_head);
				} else
					std::cout << "no key found matching with : " << val.first << BN;
			}

			/* Insert prototypes :
			iterator insert (iterator position, const value_type& val) {

			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {

			}*/

			void printBT() {
				printBT("", this->_head, false);
				std::cout << " ---> the bigger is : " << this->_leaf->parent->data->first << BN;
			}

		private :

			node*	_search(node* root, value_type const & val) {
				if (root == this->_leaf)
					return (NULL);
				else if (_compAlgo.operator()(root->data->first, val.first))
					return (this->_search(root->rightChild, val));
				else if (_compAlgo.operator()(val.first, root->data->first))
					return (this->_search(root->leftChild, val));
				else
					return (root);
			}

			node*	_transplant(node* rm, node* substitute) {
				node*	tmp = NULL;

				this->_mhandle.destroy(rm->data);
				this->_mhandle.deallocate(rm->data, 1);
				rm->data = substitute->data;

				if (substitute->rightChild == this->_leaf && substitute->leftChild == this->_leaf)
					tmp = this->_leaf;
				else if (substitute->rightChild != this->_leaf)
					tmp = substitute->rightChild;
				else if (substitute->leftChild != this->_leaf)
					tmp = substitute->leftChild;
				if (substitute->parent && (substitute->parent->rightChild == substitute))
					substitute->parent->rightChild = tmp;
				else if (substitute->parent && substitute->parent->leftChild == substitute)
					substitute->parent->leftChild = tmp;
				if (tmp != this->_leaf)
					tmp->parent = substitute->parent;
				return (tmp);
			}

			node* _find_subsitute(node *root) {
				if (root->rightChild == _leaf && root->leftChild == _leaf)
					return (root);
				else if (root->rightChild && root->leftChild == _leaf) {
					return (root->rightChild);
				}
				else if (root->leftChild && root->rightChild == _leaf) {
					return (root->leftChild);
				}
				else if (root->leftChild != _leaf && root->rightChild != _leaf) {
					node* temp = root->leftChild;
					while (temp->rightChild != _leaf)
						temp = temp->rightChild;
					return (temp);
					// return (_find_subsitute(temp));
				}
				return (NULL);
			}

			void	_checkDansQuelPetrinJeSuis(int& case_flag, node* root, node* rootParent) {
				case_flag = 0;
				if (rootParent)
				{
					case_flag |= (rootParent->leftChild == root);
					if (case_flag)
					{
						case_flag |= (rootParent->rightChild->color == RED) * 2;
						case_flag |= (rootParent->rightChild->rightChild->color == RED) * 4;
						case_flag |= (rootParent->rightChild->leftChild->color == RED) * 8;
					}
					else
					{
						case_flag |= (rootParent->leftChild->color == RED) * 2;
						case_flag |= (rootParent->leftChild->rightChild->color == RED) * 4;
						case_flag |= (rootParent->leftChild->leftChild->color == RED) * 8;
					}
					case_flag |= (rootParent->rightChild == root) * 16;
				}
			}

			void	_fixDoubleBlack(node* tmp, node* parent) {
				int	case_flag = 0;
				if (tmp == this->_head)
					return ;
				_checkDansQuelPetrinJeSuis(case_flag, tmp, parent);
				if (!(case_flag & SIBLING_IS_L) && !(case_flag & SIBLING_IS_R)) {
					if (parent && parent->parent)
						_fixDoubleBlack(parent, parent->parent);
					else
						return ;
				}
				if ((case_flag & SIBLING_IS_RED) == 0 && ((case_flag & NEPHEW_R_IS_RED) || (case_flag & NEPHEW_L_IS_RED)))
				{
					if ((case_flag & (NEPHEW_R_IS_RED + SIBLING_IS_L)) == (NEPHEW_R_IS_RED + SIBLING_IS_L)) {
						parent->leftChild->rightChild->color = parent->color;
						_leftRotation(parent->leftChild->rightChild, parent->leftChild);
						_rightRotation(parent->leftChild, parent);
					} else if ((case_flag & (NEPHEW_L_IS_RED + SIBLING_IS_L)) == (NEPHEW_L_IS_RED + SIBLING_IS_L)) {
						parent->leftChild->leftChild->color = parent->leftChild->color;
						parent->leftChild->color = parent->color;
						_rightRotation(parent->leftChild, parent);
					} else if ((case_flag & (NEPHEW_R_IS_RED + SIBLING_IS_R)) == (NEPHEW_R_IS_RED + SIBLING_IS_R)) {
						parent->rightChild->rightChild->color = parent->rightChild->color;
						parent->rightChild->color = parent->color;
						_leftRotation(parent->rightChild, parent);
					} else if ((case_flag & (NEPHEW_L_IS_RED + SIBLING_IS_R)) == (NEPHEW_L_IS_RED + SIBLING_IS_R)) {
						parent->rightChild->leftChild->color = parent->color;
						_rightRotation(parent->rightChild->leftChild, parent->rightChild);
						_leftRotation(parent->rightChild, parent);
					}
					parent->color = BLACK;
				} else if (!(case_flag & NEPHEW_R_IS_RED) && !(case_flag & NEPHEW_L_IS_RED) && (case_flag & SIBLING_IS_RED) == 0) {
					if ((case_flag & SIBLING_IS_L) == SIBLING_IS_L) {
						parent->leftChild->color = RED;
					}
					else if ((case_flag & SIBLING_IS_R) == SIBLING_IS_R) {
						parent->rightChild->color = RED;
					}
					if (parent->color == BLACK)
						_fixDoubleBlack(parent, parent->parent);
					else
						parent->color = BLACK;
				} else if ((case_flag & SIBLING_IS_RED) == SIBLING_IS_RED) {
						parent->color = RED;
						if ((case_flag & SIBLING_IS_R) == SIBLING_IS_R) {
							parent->rightChild->color = BLACK;
							_leftRotation(parent->rightChild, parent);
						} else if ((case_flag & SIBLING_IS_L) == SIBLING_IS_L) {
							parent->leftChild->color = BLACK;
							_rightRotation(parent->leftChild, parent);
						}
						_fixDoubleBlack(tmp, parent);
				}
			}

			node*	_insertNewElement(node *parent, const_reference data, bool color) {
				pointer temp = _mhandle.allocate(1);
				node*	tempNode;
				_mhandle.construct(temp, data);
				tempNode = new node(temp, parent, this->_leaf, this->_leaf, color);
				return (tempNode);
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

			node*	_findBiggestVal(node* root) {
				if (root->rightChild != this->_leaf)
					return (_findBiggestVal(root->rightChild));
				else
					return (root);
			}

			node*	_findLowestVal(node* root) {
				if (root->leftChild != this->_leaf)
					return (_findLowestVal(root->leftChild));
				else
					return (root);
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
								// std::cout << "CASE : 1\n\n";
								_rightRotation(parent, gParent);
								colorTmp = parent->color;
								parent->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case RRR :
								// std::cout << "CASE : 2 \n\n";
								_leftRotation(parent, gParent);
								colorTmp = parent->color;
								parent->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case LRR :
								// std::cout << "CASE : 3\n\n";
								_rightRotation(child, parent);
								_leftRotation(child, gParent);
								colorTmp = child->color;
								child->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case RLR :
								// std::cout << "CASE : 4\n\n";
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

			node	*_dive(node* current, const_reference data, bool & isbigger, bool & isOk) {
				node* ret = NULL;
				if (current->rightChild == this->_leaf && _compAlgo.operator()(current->data->first, data.first)) {
					current->rightChild = _insertNewElement(current, data, RED);
					current = current->rightChild;
					ret = current;
					if (isbigger)
						current->rightChild->parent = current;
				}
				else if (current->leftChild == this->_leaf && _compAlgo.operator()(data.first, current->data->first)) {
					isbigger = 0;
					current->leftChild = _insertNewElement(current, data, RED);
					current = current->leftChild;
					ret = current;
				}
				else if (_compAlgo.operator()(current->data->first, data.first)) {
					ret = _dive(current->rightChild, data, isbigger, isOk);
				}
				else if (_compAlgo.operator()(data.first, current->data->first)) {
					isbigger = 0;
					ret =_dive(current->leftChild, data, isbigger, isOk);
				}
				else {
					isOk = 0;
					isbigger = 0;
					return (current);
				}
				_balance(current);
				return (ret);
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

		/*  ------------------ MY_ITERATOR ------------------  */

	template <typename T>
	class	binary_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&> {

		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::pointer			pointer;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::difference_type	difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::value_type		value_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::reference		reference;
		typedef typename ft::map<typename remove_cv<typename T::first_type>::type, typename T::second_type>::node*	node_type;
		// typedef typename ft::map<int, int>::node*							node_type;

		//typedef typename std::iterator
		public :
		binary_tree_iterator() : _location(NULL) {  /*  nothing to put for the moment  */  }

		binary_tree_iterator(node_type start_addr, node_type leaf) {
			this->_location = start_addr;
			this->_leaf = leaf;
		}

		template <typename U>
		binary_tree_iterator(const binary_tree_iterator<U> & itToCopy) {
			*this = itToCopy;
		}

		template <typename U>
		binary_tree_iterator const & operator=(binary_tree_iterator<U> const & itToAssign) {
			this->_location = itToAssign.operator->();
			return (*this);
		}

		/*  -----------  == && != -----------  */

		template <typename U>
		bool		operator==(binary_tree_iterator<U> const & itToComp) {
			return (_location == itToComp.operator->());
		}

		template <typename U>
		bool		operator!=(binary_tree_iterator<U> const & itToComp) {
			return (_location != itToComp._location);
		}

		/*  -----------  * && -> -----------  */

		reference	operator*( void ) const {
			return (*(_location->data));
		}

		pointer	operator->( void ) const {
			return (_location->data);
		};

		/*  ---------------- ++ && -- --------------*/

		binary_tree_iterator & operator++( void ){

			if (this->_location->rightChild != this->_leaf)
			{
				if (this->_location->data->first == 1245)
					std::cout << "******************\n\n";
				this->_location = this->_location->rightChild;
				while(this->_location->leftChild != this->_leaf)
					this->_location = this->_location->leftChild;
				return (*this);
			}
			else
			{
				if (this->_location->rightChild == this->_leaf && this->_leaf->parent == this->_location) {
					this->_location = this->_leaf;
					return (*this);
				}

				while (this->_location->parent && this->_location == this->_location->parent->rightChild){
					this->_location = this->_location->parent;
				}
				this->_location = this->_location->parent;
				return (*this);
			}
		}

		// binary_tree_iterator	operator++( int ) {
			// binary_tree_iterator	temp = *this;
			// _location++;
			// return (temp);
		// }
//
		// binary_tree_iterator & operator--( void ){
			// _location--;
			// return (*this);
		// }
//
		// binary_tree_iterator	operator--( int ) {
			// binary_tree_iterator	temp = *this;
			// _location--;
			// return (temp);
		// }

		private :
		node_type	_location;
		node_type	_leaf;
	};
}

#endif
