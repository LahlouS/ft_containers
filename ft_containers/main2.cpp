#include <map>
#include <iostream>
#include "traits_utils_pair.hpp"
#include "map.hpp"
#define BN "\n"

int main(void){
	ft::map<int, int> test;

	test.insert(ft::make_pair(15, 0));
	test.insert(ft::make_pair(12, 0));
	test.insert(ft::make_pair(19, 0));
	test.insert(ft::make_pair(23, 0));
	test.insert(ft::make_pair(22, 0));
	test.insert(ft::make_pair(56, 0));

	std::cout << "\n\nbefore deletion : \n";
	test.printBT();
	std::cout << "\n\n****after deletion****" << BN;
	// test.erase(ft::make_pair(19, 0));
	test.erase(ft::make_pair(12, 0));
	test.printBT();
	return (0);
}

