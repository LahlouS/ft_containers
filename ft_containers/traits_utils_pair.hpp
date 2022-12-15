#ifndef TRAITS_UTILS_PAIR_HPP
#define TRAITS_UTILS_PAIR_HPP

namespace ft {
	template<class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		pair() { /*  nothing to put for the moment  */ }

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first) {
			second = pr.second;
		}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {
		}

		~pair(){ /*  nothing to put for the moment  */ }

		first_type first;
		second_type second;
	};

	template <class T1,class T2>
	pair<const T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}
}

#endif
