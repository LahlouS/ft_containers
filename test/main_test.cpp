#include <iostream>
#include <type_traits>

template <typename T>
struct type_is { typedef T type; };

// template <typename T>
// typedef typename type_is<T>::type type_is_t<T>;

template <bool p, typename T, typename F>
struct IF : type_is<F> {};

template <typename T, typename F>
struct IF<true, T, F> : type_is<T> {};

template <bool p, typename T, typename F>
using IF_t = typename IF<p, T, F>::type;
// typedef typename IF<p, T, F>::type IF_t;
// struct IF_t { typename IF<p, T, F>::type };

int main(void)
{
	// const bool b = false;

	IF_t<std::true_type::value, long, short> n;
	std::cout << sizeof(n) << std::endl;
	return (0);
}
