#ifndef TRAITS_UTILS_PAIR_HPP
#define TRAITS_UTILS_PAIR_HPP

namespace ft {
	template<class T1, class T2>
	struct pair {
		typedef first_type	T1;
		typedef second_type	T2;

		pair() { /*  nothing to put for the moment  */ }

		template<class U, class V>
		pair (const pair<U,V>& pr) {
			*this = pr;
		}

		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
		}

		pair (const first_type& a, const second_type& b) {
				this->first = a;
				this->second = b;
		}

		~pair(){ /*  nothing to put for the moment  */ }

		first_type first;
		second_type second;
	}

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}
}

#endif
