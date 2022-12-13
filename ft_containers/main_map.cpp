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



	std::map<int, int>::const_reverse_iterator ritVrai = testVrai.rbegin();
	ft::map<int, int>::const_reverse_iterator rit = test.rbegin();

	while (ritVrai != testVrai.rend()) {
		std::cout << ritVrai->first << "\t";
		ritVrai++;
	}
	std::cout << BN;
	while (rit != test.rend()) {
		std::cout << rit->first << "\t";
		rit++;
	}
	std::cout << BN;
	ritVrai--;
	rit--;

	// ritVrai->second = 89; // will not compile while iterators are const_reverse
	// rit->second = 89; // will not compile while iterators are const_reverse

	while (ritVrai != testVrai.rbegin()) {
		std::cout << ritVrai->second << "\t";
		ritVrai--;
	}
	std::cout << BN;
	while (rit != test.rbegin()) {
		std::cout << rit->second << "\t";
		rit--;
	}
	std::cout << BN << BN;
	std::cout << "some test on different insert functions : " << BN;
	std::cout << "first to last iterators insertion :\n";
	ft::map<int, int> test2;
	std::map<int, int> testVrai2;

	test2.insert(test.begin(), test.end());
	testVrai2.insert(testVrai.begin(), testVrai.end());

	ft::map<int, int>::iterator it2 = test2.begin();
	std::map<int, int>::iterator itVrai2 = testVrai2.begin();

	std::cout << "it2" << "\t" << "itVrai2" << BN;
	for (; it2 != test2.end(); it2++, itVrai2++) {
		std::cout << it2->first << "\t" << itVrai2->first << BN;
	}
	std::cout << BN;
	std::cout << "check return value of  'pair<iterator,bool> insert (const value_type& val)' :\n";

	std::cout << "testVrai2.insert(std::make_pair(788456, 0)).second -> " << testVrai2.insert(std::make_pair(788456, 0)).second << BN;
	std::cout << "test2.insert(ft::make_pair(788456, 0)).second -> " << test2.insert(ft::make_pair(788456, 0)).second << BN;

	std::cout << "testVrai2.insert(std::make_pair(788456, 0)).first->first -> " << testVrai2.insert(std::make_pair(788456, 0)).first->first << BN;
	std::cout << "test2.insert(ft::make_pair(788456, 0)).first->first -> " << test2.insert(ft::make_pair(788456, 0)).first->first << BN << BN;

	std::cout << "same but with a key_value that already exist : \n";
	std::cout << "testVrai2.insert(std::make_pair(100, 0)).second -> " << testVrai2.insert(std::make_pair(100, 0)).second << BN;
	std::cout << "test2.insert(ft::make_pair(100, 0)).second -> " << test2.insert(ft::make_pair(100, 0)).second << BN;

	std::cout << "testVrai2.insert(std::make_pair(100, 0)).first->first -> " << testVrai2.insert(std::make_pair(100, 0)).first->first << BN;
	std::cout << "test2.insert(ft::make_pair(100, 0)).first->first -> " << test2.insert(ft::make_pair(100, 0)).first->first << BN;

	std::cout << "Now printing all values to be sure we are all good :\n";

	it2 = test2.begin();
	itVrai2 = testVrai2.begin();

	std::cout << "it2" << "\t" << "itVrai2" << BN;
	for (; it2 != test2.end(); it2++, itVrai2++)
		std::cout << it2->first << "\t" << itVrai2->first << BN;

	if (itVrai2 == testVrai2.end())
		std::cout << "oui\n";
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


	// testVrai.erase(23);
	// test.erase(23);

	// ft::map<int, int>::iterator it = test.end();
	// std::map<int, int>::iterator itVrai = testVrai.end();
	// --itVrai;
	// --it;
	// std::cout << itVrai->first << " " << it->first << BN << BN;
	// std::cout << "V\tPV" << BN;
	// for (;itVrai != testVrai.begin();) {
	// 	std::cout << itVrai->first << " " << it->first << BN;
	// 	--itVrai;
	// 	--it;
	// }
	// std::cout << "." << (itVrai)->first << " " << it->first << BN;
	// --itVrai;
	// --it;
	// itVrai++;
	// it++;
	// itVrai++;
	// it++;
	// itVrai++;
	// it++;
	// itVrai++;
	// it++;
	// itVrai++;
	// it++;
	// std::cout << "LA ->> " << (itVrai)->first << " " << it->first << BN;
