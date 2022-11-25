#include <iostream>
#include <string>
#include "vector.hpp"

int main( void )
{
	//std::cout << "bonjour\n";
	vector<int> test(5, 12);
	vector<int>::iterator it = test.begin();

	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	return (0);
}
