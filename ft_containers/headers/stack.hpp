#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

	template <typename T, class Container = ft::vector<T> >
	class stack {
		public :
			typedef	Container								container_type;
			typedef	typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;

			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {
				/*  nothing to put for the moment  */
			}

			bool empty() const {
				return (c.empty());
			}

			size_type size() const {
				return (c.size());
			}

			reference top() {
				return ((c.back()));
			}

			const_reference top() const {
				return ((c.back()));
			}

			void push (const value_type& val) {
				c.push_back(val);
			}

			void pop() {
				c.pop_back();
			}

			/* ***  need friend declaration so my non member overload may access the private container c  *** */

			template <class U, class V>
			friend bool operator==(const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator!=(const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator<(const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator<=(const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator>(const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator>=(const stack<U,V>& lhs, const stack<U,V>& rhs);

		protected :
			Container c;
	};

	template <class U, class V>
	bool operator== (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c == rhs.c);
	}

	template <class U, class V>
	bool operator!= (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c != rhs.c);
	}

	template <class U, class V>
	bool operator<  (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c < rhs.c);
	}

	template <class U, class V>
	bool operator<= (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c <= rhs.c);
	}

	template <class U, class V>
	bool operator>  (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c > rhs.c);
	}

	template <class U, class V>
	bool operator>= (const stack<U,V>& lhs, const stack<U,V>& rhs){
		return (lhs.c >= rhs.c);
	}
}


#endif
