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
	test.insert(ft::make_pair(26, 0));
	test.insert(ft::make_pair(7, 0));
	test.insert(ft::make_pair(5, 0));
	test.insert(ft::make_pair(14, 0));
	test.insert(ft::make_pair(13, 0));
	test.insert(ft::make_pair(17, 0));
	test.insert(ft::make_pair(12, 0));
	test.insert(ft::make_pair(11, 0));
	test.insert(ft::make_pair(55, 0));
	test.insert(ft::make_pair(25, 0));
	test.insert(ft::make_pair(34, 0));
	test.insert(ft::make_pair(18, 0));
	test.insert(ft::make_pair(23, 0));
	test.insert(ft::make_pair(42, 0));


	test.printBT();
	return (0);
}

