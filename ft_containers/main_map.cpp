#include <map>
#include <iostream>
#include "traits_utils_pair.hpp"
#include "map.hpp"
#define BN "\n"

int main(void){

	ft::map<int, int> test;

	test.insert(ft::make_pair(15, 0));
	test.insert(ft::make_pair(12, 0));
	test.insert(ft::make_pair(32, 0));
	test.insert(ft::make_pair(56, 0));
	test.insert(ft::make_pair(1, 0));
	test.insert(ft::make_pair(7, 0));
	test.insert(ft::make_pair(9, 0));
	test.insert(ft::make_pair(23, 0));
	test.insert(ft::make_pair(89, 0));
	test.insert(ft::make_pair(100, 0));
	test.insert(ft::make_pair(66, 0));
	test.insert(ft::make_pair(4, 0));
	test.insert(ft::make_pair(1045, 0));
	test.insert(ft::make_pair(1042, 0));
	test.insert(ft::make_pair(104, 0));
	test.insert(ft::make_pair(1245, 0));
	test.insert(ft::make_pair(-104, 0));



	std::map<int, int> testVrai;

	testVrai.insert(std::make_pair(15, 0));
	testVrai.insert(std::make_pair(12, 0));
	testVrai.insert(std::make_pair(32, 0));
	testVrai.insert(std::make_pair(56, 0));
	testVrai.insert(std::make_pair(1, 0));
	testVrai.insert(std::make_pair(7, 0));
	testVrai.insert(std::make_pair(9, 0));
	testVrai.insert(std::make_pair(23, 0));
	testVrai.insert(std::make_pair(89, 0));
	testVrai.insert(std::make_pair(100, 0));
	testVrai.insert(std::make_pair(66, 0));
	testVrai.insert(std::make_pair(4, 0));
	testVrai.insert(std::make_pair(1045, 0));
	testVrai.insert(std::make_pair(1042, 0));
	testVrai.insert(std::make_pair(104, 0));
	testVrai.insert(std::make_pair(1245, 0));
	testVrai.insert(std::make_pair(-104, 0));


	//std::map<int, int>::iterator itVrai = testVrai.begin();
	ft::map<int, int>::iterator it = test.begin();

	std::cout << "V\tPV" << BN;
	for (;it != test.end();) {
		std::cout << it->first << BN;
		++it;
	}

	return (0);
}

// ft::map<int, int> test;
//
	// test.insert(ft::make_pair(15, 0));
	// test.insert(ft::make_pair(12, 0));
	// test.insert(ft::make_pair(32, 0));
	// test.insert(ft::make_pair(56, 0));
	// test.insert(ft::make_pair(1, 0));
	// test.insert(ft::make_pair(7, 0));
	// test.insert(ft::make_pair(9, 0));
	// test.insert(ft::make_pair(23, 0));
	// test.insert(ft::make_pair(89, 0));
	// test.insert(ft::make_pair(100, 0));
	// test.insert(ft::make_pair(66, 0));
	// test.insert(ft::make_pair(4, 0));
	// test.insert(ft::make_pair(1045, 0));
	// test.insert(ft::make_pair(1042, 0));
	// test.insert(ft::make_pair(104, 0));
	// test.insert(ft::make_pair(1245, 0));
	// test.insert(ft::make_pair(-104, 0));
//
	// std::cout << "----------- > size : " << test.size();
	// std::cout << "\n\nbefore deletion : \n";
	// test.printBT();
	// std::cout << "\n\n****after deletion****" << BN;
	// test.erase(ft::make_pair(56, 0));
	// test.erase(ft::make_pair(23, 0));
	// test.erase(ft::make_pair(15, 0));
	// test.erase(ft::make_pair(66, 0));
	// test.erase(ft::make_pair(12, 0));
	// test.erase(ft::make_pair(1, 0));
	// test.erase(ft::make_pair(32, 0));
	// test.erase(ft::make_pair(9, 0));
	// test.erase(ft::make_pair(89, 0));
	// test.erase(ft::make_pair(7, 0));
	// test.erase(ft::make_pair(4, 0));
	// test.erase(ft::make_pair(100, 0));
	// test.erase(ft::make_pair(1245, 0));
//
	// test.printBT();