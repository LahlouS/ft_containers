#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>
#include "vector.hpp"


int main( void )
{
	ft::vector<int> 			test(5, 42);
	ft::vector<int> 			test_range(test.begin(), test.end());
	ft::vector<int>::iterator	it = test.begin();
	ft::vector<int>::iterator	it_range = test_range.begin();
	int i = 0;
	std::cout << BN << "***testing iterators loop and wellness of initilisation (range constructor and value constructor)*** : " << BN << BN;
	std::cout << "while (it != test.end()) { " << BN << BN;
	while (it != test.end()) {
		std::cout << "value " << i++ << " : " << *it++ << " == " << *it_range++ << BN;
	}
	if (it == test.end())
		std::cout << BN << "it == test.end()\n\n";
	std::cout << "}\n\n--> for (int i = 0; i < 5; i++) std::cout << *(it + i) {\n";

	it = test.begin();
	for (int i = 0; i < 5; i++)
		std::cout << *(it + i) << " ";
	std::cout << BN;

	std::cout << "}\n\n--> and know testing the '-' operator with it = test.end() - 1 {\n";

	it = (test.end() - 1);
	for (int i = 0; i != 5; i++)
		std::cout << *(it - i) << " ";
	std::cout << BN;

	std::cout << "}" << BN << BN;

	std::cout << "\n\n--> it += / -= 4 {" << BN;
	std::cout << *(it -= 4) << BN;
	std:: cout << *(it += 4) << BN;
	std::cout << "}\n";

	std::cout << "***" << BN << BN;

	std::cout << "***CHAR_TRAITS TEST*** :" << BN << BN <<"sizeof(ft::iterator_traits<long *>::value_type) : " << sizeof(ft::iterator_traits<long *>::value_type) << BN;
	if (typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test VRAI" << BN;
	else
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test FAUX" << BN;
	std::cout << "***" << BN;

	std::cout << "***TESTING IS_INTEGRAL TEMPLATE***" << BN << BN;
	std::cout << std::boolalpha;
	std::cout << "char : " << ft::is_integral<char>::value << std::endl;
	std::cout << "const char : " << ft::is_integral<const char >::value << std::endl;
	std::cout << "const volatile int : " << ft::is_integral<const volatile int>::value << std::endl;
	std::cout << "float : " << ft::is_integral<float>::value << BN;
	std::cout << "int : " << ft::is_integral<int>::value << BN;
	std::cout << "ft::vector<int> : " << ft::is_integral<ft::vector<int> >::value << BN;
	std::cout << "ft::vector<int>::iterator : " << ft::is_integral<ft::vector<int>::iterator>::value << BN;
	std::cout << "short : " << ft::is_integral<short>::value << BN;
	std::cout << "***" << BN;
	{
		std::cout << "testing iterators attributtes (const / non const)" << BN;
		ft::vector<int> test(5, 12);
		ft::vector<int>::iterator it = test.begin();

		*it = 16;
		*(it + 1) = 42;

		while (it != test.end())
			std::cout << *it++ << BN;

	}

	{
		std::cout << BN << "***  TESTING INSERT FUNCTION  ***" << BN;
		ft::vector<int> test_insert;

		std::cout << "Printing insert return value : " << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 42)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 56)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin() + 1, 489)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin() + 2, 1)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 506)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 420)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 560)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 4890)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 10)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 5060)) << BN;

		std::cout << BN << "printing vector attributes :" << BN << BN;
		for (ft::vector<int>::iterator	it = test_insert.begin(); it != test_insert.end(); it++)
			std::cout << *it << " ";
		std::cout << BN;

		std::cout << "\n***\n";
	}

	{
		std::cout << BN << "\n\n***  TESTING WITH THE REAL VECTOR  ***" << BN;
		std::vector<int> test_insert;
		std::cout << "Printing insert return value : " << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 42)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 56)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin() + 1, 489)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin() + 2, 1)) << BN;
		std::cout << *(test_insert.insert(test_insert.begin(), 506)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 420)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 560)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 4890)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 10)) << BN;
		std::cout << *(test_insert.insert(test_insert.end(), 5060)) << BN;

		std::cout << BN << "printing vector attributes :" << BN << BN;
		for (std::vector<int>::iterator it = test_insert.begin(); it != test_insert.end(); it++)
			std::cout << *it << " ";
		std::cout << BN;
		std::cout << "\n***\n";
	}

	{
		std::vector<int> test_myvector;
		ft::vector<int> test_vector;

		std::cout << "testing with multiple entry" << BN << "--> insert(vec.begin(), 12, 42)" << BN;
		test_myvector.insert(test_myvector.begin(), 12, 52);
		test_vector.insert(test_vector.begin(), 12, 52);
		std::cout << "test_myvector[i] == << test_vector[i]" << BN;
		for (int i = 0; i < 12; i++) {
			std::cout << "--> " << test_myvector[i] << "      ==     " << test_vector[i] << BN;
		}

	}

	{
		ft::vector<int> test(5, 12);
		ft::vector<int> test_range;
		std::cout << "***testing range insertion***" << BN;
		test_range.insert(test_range.begin(), test.begin(), test.end());
		std::cout << "--> initial vector :\n";
		test.print();
		std::cout << "--> vector init from range:\n";
		test_range.print();

		std::cout << "FIN DU TEST\n\n";

	}
	return (0);
}


// int main (void) {
// 	std::vector<int> test;
// 	std::vector<int>::iterator it = test.end();

// 	test.insert(it, 1, 25);
// 	test.insert(test.end(), 1, 35);
// 	test.insert(test.end(), 1, 45);

// 	std::cout << "ici mon test : " << test[0] << "\n";
// 	std::cout << "ici mon test : " << test[1] << "\n";
// 	std::cout << "ici mon test : " << test[2] << "\n";
// 	std::cout << "\n";


// 	return (0);
// }
