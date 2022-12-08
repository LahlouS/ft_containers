#include <map>
#include <iostream>
#include "traits_utils_pair.hpp"
#include "map.hpp"
#define BN "\n"

int main(void){
	ft::map<int, int> test;

	test.insert(ft::make_pair(3, 0));
	test.insert(ft::make_pair(21, 0));
	test.insert(ft::make_pair(32, 0));
	test.insert(ft::make_pair(15, 0));
	test.insert(ft::make_pair(16, 0));
	test.insert(ft::make_pair(24, 0));
	test.insert(ft::make_pair(7, 0));


	test.printBT();
	return (0);
}

