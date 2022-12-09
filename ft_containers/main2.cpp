#include <map>
#include <iostream>
#include "traits_utils_pair.hpp"
#include "map.hpp"
#define BN "\n"

int main(void){
	ft::map<int, int> test;

	test.insert(ft::make_pair(20, 0));
	test.insert(ft::make_pair(10, 0));
	test.insert(ft::make_pair(30, 0));
	test.insert(ft::make_pair(25, 0));
	test.insert(ft::make_pair(35, 0));

	std::cout << "\n\nbefore deletion : \n";
	test.printBT();
	// std::cout << "\n\n****after deletion****" << BN;
	test.erase(ft::make_pair(35, 0));
	// test.printBT();
	return (0);
}

