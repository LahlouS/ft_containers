#include <iostream>
#include <string>
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

	std::cout << "CHAR_TRAITS TEST\n : sizeof(ft::iterator_traits<long *>::value_type) : " << sizeof(ft::iterator_traits<long *>::value_type) << NL;
	std::cout << << NL;
	return (0);
}
