#include <map>
#include <iostream>
#include "traits_utils_pair.hpp"
#include "map.hpp"
#define BN "\n"

int main(void){
	ft::map<int, int> test;

	test.insert(ft::make_pair(5, 0));
	test.insert(ft::make_pair(10, 0));
	test.insert(ft::make_pair(9, 0));


	test.printBT();
	return (0);
}

