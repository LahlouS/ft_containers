#ifndef MAP_HPP
#define MAP_HPP

#include "traits_utils.hpp"
#include "traits_utils_pair.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>

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
	template <typename T, typename C, typename N>
	class	binary_tree_iterator;

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
		class map {
			public :
			struct node;
		/*  -------------  Member_types  -----------------------------------*/

			typedef				Key														key_type;
			typedef				T														mapped_value;
			typedef	typename	ft::pair<const Key, T>									value_type;
			typedef				std::size_t												size_type;
			typedef				std::ptrdiff_t											difference_type;
			typedef				Compare													key_compare;
			typedef				Allocator												allocator_type;
			typedef				value_type&												reference;
			typedef				const value_type&										const_reference;
			typedef	typename	Allocator::pointer										pointer;
			typedef	typename	Allocator::const_pointer								const_pointer;
			typedef				binary_tree_iterator<value_type, Compare, node*>		iterator;
			typedef				binary_tree_iterator<const value_type, Compare, node*>	const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

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

			class value_compare {
					friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			/*  -------------  Constructors  -----------------------------------*/
			explicit map( const Compare& comp = key_compare(), const Allocator& alloc = Allocator() ) : _mhandle(alloc), _head(NULL), _size(0), _capacity(0), _compAlgo(comp) {
				_leaf = new node;
				_head = _leaf;
				_leaf->leftChild = _leaf->rightChild = NULL;
			}

			map (const map& x) : _head(NULL), _size(0), _capacity(0) {
				_leaf = new node;
				_leaf->leftChild = _leaf->rightChild = NULL;
				_head = _leaf;
				*this = x;
			}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _mhandle(alloc), _head(NULL), _size(0), _capacity(0), _compAlgo(comp) {
				_leaf = new node;
				_head = _leaf;
				_leaf->leftChild = _leaf->rightChild = NULL;
				this->insert(first, last);
			}

			map&	operator=(const map& x) {
				if (this->_head != this->_leaf)
					this->_freeTree(this->_head);
				this->_size = 0;
				_head = _leaf;
				this->insert(x.begin(), x.end());
				return (*this);
			}

			~map() {
				if (this->_head != this->_leaf)
					this->_freeTree(this->_head);
				delete _leaf;
			}

			/* ------------------  Iterators stuff  ---------------------- */

			iterator		begin() {
					return (iterator(this->_findLowestVal(this->_head), this->_leaf));
			}

			const_iterator	begin() const {
					// std::cout << "ldlwdlksdhfkjdfhvsdklgnvdf\n\n";
					return (const_iterator(this->_findLowestVal(this->_head), this->_leaf));
			}

			iterator		end(void) {
				return (iterator(this->_leaf, this->_leaf));
			}

			const_iterator		end(void) const {
				return (const_iterator(this->_leaf, this->_leaf));
			}


			reverse_iterator rbegin(void) {
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator rend(void) {
				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator rend() const{
				return (const_reverse_iterator(this->begin()));
			}

			/*  ----------------------- Modifiers -------------------------  */


			void		erase(iterator first, iterator last) {
				while (first != last) {
					value_type tmp(*first++);
					this->_erase(tmp);
				}
			}

			void		erase (iterator position) {
				this->_erase(*position);
			}

			size_type	erase(const key_type &val) {
				return (this->_erase(ft::make_pair<key_type, bool>(val, 0)));
			}

			//Insert
			ft::pair<iterator,bool> insert(const value_type& val) {
				node*	ret = NULL;
				bool	isbigger = 1;
				bool	isOk	 = 1;
				if (this->_head != _leaf)
					ret = this->_dive(_head, val, isbigger, isOk);
				else
				{
					ret = this->_head = _insertNewElement(NULL, val, BLACK);
					this->_leaf->parent = this->_head;
				}
				if (isOk)
					this->_size += 1;
				return (ft::make_pair<iterator, bool>(iterator(ret, this->_leaf), isOk));
			}

			iterator insert (iterator position, const value_type& val) {
				node*	ret = NULL;
				bool	isbigger = 1;
				bool	isOk	 = 1;

				(void)position;
				if (this->_head != _leaf)
					ret = this->_dive(_head, val, isbigger, isOk);
				else {
					ret = this->_head = _insertNewElement(NULL, val, BLACK);
					this->_leaf->parent = this->_head;
				}
				if (isOk)
					this->_size += 1;
				return (iterator(ret, this->_leaf));
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last, typename enable_if< !is_integral<InputIterator>::value, int>::type = 0) {
				while (first != last){
					insert(*first);
					first++;
				}
			}

			void	clear(void) {
				if (this->_head != this->_leaf)
					this->_freeTree(this->_head);
				this->_head = this->_leaf;
				this->_leaf->parent = NULL;
				this->_size = 0;
			}

			void swap(map & x) {
				allocator_type	tmp_mhandle = _mhandle;
				node*			tmp_head = _head;
				node*			tmp_leaf = _leaf;
				size_type		tmp_size = _size;
				size_type		tmp_capacity = _capacity;
				key_compare		tmp_compAlgo = _compAlgo;

				this->_mhandle = x._mhandle;
				this->_head = x._head;
				this->_leaf = x._leaf;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_compAlgo = x._compAlgo;

				x._mhandle = tmp_mhandle;
				x._head = tmp_head;
				x._leaf = tmp_leaf;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
				x._compAlgo = tmp_compAlgo;
			}

			/*  ----------------------- Capacity ------------------------------*/

			size_type	size() const {
				return (this->_size);
			}

			bool		empty() const {
				return ((this->_size == 0));
			}

			size_type max_size() const {
				return (_mhandle.max_size());
			}

			/*  ----------------------- Element Access ------------------------------*/

			mapped_value&	operator[] (const key_type& k) {
				node* tmp = this->_search(this->_head, k);
				if (tmp)
					return (tmp->data->second);
				else {
					iterator tmp = this->begin();
					return ( this->insert(tmp, ft::make_pair(k, mapped_value()))->second );
				}
			}

			mapped_value& at(const key_type& k){
				node* tmp = this->_search(this->_head, k);
				if (!tmp)
					throw std::out_of_range("ERREUR: Une erreur a ete detecte entre la chaise et le clavier !");
				return (tmp->data->second);
			}

			const mapped_value& at (const key_type& k) const {
				node* tmp = this->_search(this->_head, k);
				if (!tmp)
					throw std::out_of_range("ERREUR: Une erreur a ete detecte entre la chaise et le clavier !");
				return (tmp->data->second);
			}


			/* -------------------------- observer ---------------------- */

			key_compare key_comp() const {
				return (this->_compAlgo);
			}
			value_compare	value_comp() const {
				return (value_compare(this->_compAlgo));
			}


			/* -------------------------- Operations ---------------------- */

			iterator find(const key_type& k) {
				node* tmp = this->_search(this->_head, k);
				if (tmp)
					return (iterator(tmp, this->_leaf));
				return (this->end());
			}

			const_iterator find (const key_type& k) const {
				node* tmp = this->_search(this->_head, k);
				if (tmp)
					return (const_iterator(tmp, this->_leaf));
				return (this->end());
			}

			size_type count (const key_type& k) const {
				node* tmp = this->_search(this->_head, k);
				if (tmp)
					return (1);
				return (0);
			}


			iterator lower_bound (const key_type& k){
				iterator it = this->begin();
				iterator ite = this->end();
				for (; it != ite;it++)
					if (!this->_compAlgo(it->first, k))
						return (it);
				return (it);
			}

			const_iterator lower_bound (const key_type& k) const {
				const_iterator it = this->begin();
				const_iterator ite = this->end();
				for (; it != ite;it++)
					if (!this->_compAlgo(it->first, k))
						return (it);
				return (it);
			}

			iterator upper_bound (const key_type& k) {
				iterator it = this->begin();
				iterator ite = this->end();
				for (; it != ite;it++)
					if (this->_compAlgo(k, it->first))
						return (it);
				return (it);
			}

			const_iterator upper_bound (const key_type& k) const{
				const_iterator it = this->begin();
				const_iterator ite = this->end();
				for (; it != ite;it++)
					if (this->_compAlgo(k, it->first))
						return (it);
				return (it);
			}


			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::make_pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}


			pair<iterator,iterator>	equal_range (const key_type& k) {
				return (ft::make_pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			/* -------------------------- RBtree visualiser ---------------------- */


			void printBT() {
				printBT("", this->_head, false);
			}

		private :

			size_type	_erase(const value_type& val) {
				node*	rm			= _search(this->_head, val.first);
				node*	substitute	= NULL;
				if (this->_head == this->_leaf || !this->_size )
					return (0);
				if (rm) {
					substitute = _find_subsitute(rm);
					node *legacy = _transplant(rm, substitute);
					if (substitute->color == BLACK && legacy->color == BLACK && substitute != this->_head) // meaning double black shit
						_fixDoubleBlack(legacy, substitute->parent);
					else
						legacy->color = BLACK;
					if (substitute == this->_head)
						this->_head = legacy;
					delete substitute;
					this->_size -= 1;
					if (this->_head != this->_leaf)
						this->_leaf->parent = _findBiggestVal(this->_head);
					return (1);
				} else
					return (0);
			}

			node*	_search(node* root, key_type const & val) const {
				if (root == this->_leaf)
					return (NULL);
				else if (_compAlgo.operator()(root->data->first, val))
					return (this->_search(root->rightChild, val));
				else if (_compAlgo.operator()(val, root->data->first))
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
				else if (root->leftChild && root->rightChild == _leaf) {
					return (root->leftChild);
				}
				else if (root->leftChild != _leaf && root->rightChild != _leaf) {
					node* temp = root->leftChild;
					while (temp->rightChild != _leaf)
						temp = temp->rightChild;
					return (temp);
				}

				return (root);
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

			node*	_findLowestVal(node* root) const {
				if (root != this->_leaf && root->leftChild != this->_leaf)
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
								_rightRotation(parent, gParent);
								colorTmp = parent->color;
								parent->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case RRR :
								_leftRotation(parent, gParent);
								colorTmp = parent->color;
								parent->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case LRR :
								_rightRotation(child, parent);
								_leftRotation(child, gParent);
								colorTmp = child->color;
								child->color = gParent->color;
								gParent->color = colorTmp;
								break ;
							case RLR :
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

					if (nude != this->_leaf)
						std::cout << "(" << nude->data->first << ")" << (nude->color ? "R" : "B" ) << std::endl;
					else
						std::cout << " #" << std::endl;
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

	template <typename T, typename C, typename N>
	class	binary_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&> {
		public :

		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::pointer				pointer;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::difference_type		difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::value_type			value_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&>::reference			reference;
		typedef			 N																								node_type;

		/*  -------------------- iterators Constructors ----------------------*/

		binary_tree_iterator() : _location(NULL), _leaf(NULL) {  /*  nothing to put for the moment  */  }


		binary_tree_iterator(node_type start_addr, node_type leaf) {
			this->_location = start_addr;
			this->_leaf = leaf;
		}

		binary_tree_iterator(binary_tree_iterator<typename remove_cv<T>::type, C, N> const & itToCopy)  : _location(itToCopy.data()), _leaf(itToCopy.data2()) {
		}

		binary_tree_iterator const & operator=(binary_tree_iterator<typename remove_cv<T>::type, C, N> const & itToAssign){
			this->_location = itToAssign.data();
			this->_leaf = itToAssign.data2();
			return (*this);
		}

		/*  -----------  == && != -----------  */

		template <typename U, typename P, typename S>
		bool		operator==(binary_tree_iterator<U, P, S> const & itToComp) const {
			return (_location == itToComp.data());
		}

		template <typename U, typename P, typename S>
		bool		operator!=(binary_tree_iterator<U, P, S> const & itToComp) const {
			return (this->_location != itToComp.data());
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
			if (this->_location->rightChild != this->_leaf && this->_location != this->_leaf)
			{
				this->_location = this->_location->rightChild;
				while(this->_location->leftChild != this->_leaf)
					this->_location = this->_location->leftChild;
				return (*this);
			} else {
				if (this->_location->rightChild == this->_leaf && this->_leaf->parent == this->_location) {
					this->_location = this->_leaf;
					return (*this);
				}

				while (this->_location->parent && this->_location == this->_location->parent->rightChild && this->_location != this->_location->parent->leftChild){
					this->_location = this->_location->parent;
				}
				if (this->_location->parent)
					this->_location = this->_location->parent;
				return (*this);
			}
		}

		binary_tree_iterator	operator++( int ) {
			binary_tree_iterator	temp = *this;
			++(*this);
			return (temp);
		}

		binary_tree_iterator & operator--( void ){
			if (this->_location->leftChild && this->_location->rightChild && this->_location->leftChild != this->_leaf)
			{
				this->_location = this->_location->leftChild;
				while (this->_location->rightChild != this->_leaf)
					this->_location = this->_location->rightChild;
				return (*this);
			} else {
				while (this->_location->parent && this->_location == this->_location->parent->leftChild && this->_location != this->_location->parent->rightChild)
				{
					this->_location = this->_location->parent;
				}
				if (this->_location->parent)
					this->_location = this->_location->parent;
				else
					this->_location = this->_leaf;
				return (*this);
			}
		}

		binary_tree_iterator	operator--( int ) {
			binary_tree_iterator	temp = *this;
			--(*this);
			return (temp);
		}

		node_type	data(void) const {
			return (_location);
		}

		node_type	data(void) {
			return (_location);
		}

		node_type	data2(void) const {
			return (_leaf);
		}

		node_type	data2(void) {
			return (_leaf);
		}

		private :
		node_type	_location;
		node_type	_leaf;
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itbeg = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itend = lhs.end();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itbeg2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itend2 = rhs.end();

		for (; itbeg != itend; itbeg++, itbeg2++)
		{
			if (itbeg2 == itend2 || itbeg->first != itbeg2->first || itbeg->second != itbeg2->second)
				return (false);
		}
		return (itbeg == itend && itbeg2 == itend2);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itbeg = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itend = lhs.end();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itbeg2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator itend2 = rhs.end();

		for (; itbeg != itend && itend2 != itbeg2; itbeg++, itbeg2++) {
			if ((itbeg->second > itbeg2->second))
				return (false);
			else if (itbeg->second < itbeg2->second)
				return (true);
		}
		if (itbeg2 != itend2)
		{
			return (true);
		}
		return (false);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (((lhs < rhs) || (lhs == rhs)));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs) && !(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs) || (lhs == rhs));
	}
}

#endif
