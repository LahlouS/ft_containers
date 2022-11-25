#include <iostream>
#include <string>
#include <typeinfo>
#include "vector.hpp"
#define NL "\n"

int main( void )
{
	//std::cout << "bonjour\n";
	ft::vector<int> test(5, 12);
	ft::vector<int>::iterator it = test.begin();
	int i = 0;
	while (it != test.end())
		std::cout << "value " << i++ << " : " << *it++ << NL;

	std::cout << "CHAR_TRAITS TEST : \nsizeof(ft::iterator_traits<long *>::value_type) : " << sizeof(ft::iterator_traits<long *>::value_type) << NL;
	if (typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category) == typeid(std::bidirectional_iterator_tag))
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test VRAI" << NL;
	else
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test FAUX" << NL;
	return (0);
}
