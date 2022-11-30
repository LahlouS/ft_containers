#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>
#include "vector.hpp"


int main( void )
{
	// ft::vector<int> 			test(5, 42);
	// ft::vector<int> 			test_range(test.begin(), test.end());
	// ft::vector<int>::iterator	it = test.begin();
	// ft::vector<int>::iterator	it_range = test_range.begin();
	// int i = 0;
	// std::cout << BN << "***testing iterators loop and wellness of initilisation (range constructor and value constructor)*** : " << BN << BN;
	// std::cout << "while (it != test.end()) { " << BN << BN;
	// while (it != test.end()) {
	// 	std::cout << "value " << i++ << " : " << *it++ << " == " << *it_range++ << BN;
	// }
	// if (it == test.end())
	// 	std::cout << BN << "it == test.end()\n\n";
	// std::cout << "}\n\n--> for (int i = 0; i < 5; i++) std::cout << *(it + i) {\n";

	// it = test.begin();
	// for (int i = 0; i < 5; i++)
	// 	std::cout << *(it + i) << " ";
	// std::cout << BN;

	// std::cout << "}\n\n--> and know testing the '-' operator with it = test.end() - 1 {\n";

	// it = (test.end() - 1);
	// for (int i = 0; i != 5; i++)
	// 	std::cout << *(it - i) << " ";
	// std::cout << BN;

	// std::cout << "}" << BN << BN;

	// std::cout << "\n\n--> it += / -= 4 {" << BN;
	// std::cout << *(it -= 4) << BN;
	// std:: cout << *(it += 4) << BN;
	// std::cout << "}\n";

	// std::cout << "***" << BN << BN;

	// std::cout << "***CHAR_TRAITS TEST*** :" << BN << BN <<"sizeof(ft::iterator_traits<long *>::value_type) : " << sizeof(ft::iterator_traits<long *>::value_type) << BN;
	// if (typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category) == typeid(std::random_access_iterator_tag))
	// 	std::cout << "[ft::iterator_traits<long *>::iterator_category] : test VRAI" << BN;
	// else
	// 	std::cout << "[ft::iterator_traits<long *>::iterator_category] : test FAUX" << BN;
	// std::cout << "***" << BN;

	// std::cout << "***TESTING IS_INTEGRAL TEMPLATE***" << BN << BN;
	// std::cout << std::boolalpha;
	// std::cout << "char : " << ft::is_integral<char>::value << std::endl;
	// std::cout << "const char : " << ft::is_integral<const char >::value << std::endl;
	// std::cout << "const volatile int : " << ft::is_integral<const volatile int>::value << std::endl;
	// std::cout << "float : " << ft::is_integral<float>::value << BN;
	// std::cout << "int : " << ft::is_integral<int>::value << BN;
	// std::cout << "ft::vector<int> : " << ft::is_integral<ft::vector<int> >::value << BN;
	// std::cout << "ft::vector<int>::iterator : " << ft::is_integral<ft::vector<int>::iterator>::value << BN;
	// std::cout << "short : " << ft::is_integral<short>::value << BN;
	// std::cout << "***" << BN;
	// {
	// 	std::cout << "testing iterators attributtes (const / non const)" << BN;
	// 	ft::vector<int> test(5, 12);
	// 	ft::vector<int>::iterator it = test.begin();

	// 	*it = 16;
	// 	*(it + 1) = 42;

	// 	while (it != test.end())
	// 		std::cout << *it++ << BN;

	// }

	// {
	// 	std::cout << BN << "***  TESTING INSERT FUNCTION  ***" << BN;
	// 	ft::vector<int> test_insert;

	// 	std::cout << "Printing insert return value : " << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 42)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 56)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin() + 1, 489)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin() + 2, 1)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 506)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 420)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 560)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 4890)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 10)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 5060)) << BN;

	// 	std::cout << BN << "printing vector attributes :" << BN << BN;
	// 	for (ft::vector<int>::iterator	it = test_insert.begin(); it != test_insert.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << BN;

	// 	std::cout << "\n***\n";
	// }

	// {
	// 	std::cout << BN << "\n\n***  TESTING WITH THE REAL VECTOR  ***" << BN;
	// 	std::vector<int> test_insert;
	// 	std::cout << "Printing insert return value : " << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 42)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 56)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin() + 1, 489)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin() + 2, 1)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.begin(), 506)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 420)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 560)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 4890)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 10)) << BN;
	// 	std::cout << *(test_insert.insert(test_insert.end(), 5060)) << BN;

	// 	std::cout << BN << "printing vector attributes :" << BN << BN;
	// 	for (std::vector<int>::iterator it = test_insert.begin(); it != test_insert.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << BN;
	// 	std::cout << "\n***\n";
	// }

	// {
	// 	ft::vector<int> test_myvector;
	// 	std::vector<int> test_vector;

	// 	std::cout << "testing with multiple entry" << BN << "--> insert(vec.begin(), 12, 42)" << BN;
	// 	test_myvector.insert(test_myvector.begin(), 12, 52);
	// 	test_vector.insert(test_vector.begin(), 12, 52);
	// 	std::cout << "test_myvector[i] == << test_vector[i]" << BN;
	// 	for (int i = 0; i < 12; i++) {
	// 		std::cout << "--> " << test_myvector[i] << "      ==     " << test_vector[i] << BN;
	// 	}
	// 	std::cout << BN << "-->testing erase function :" << BN;
	// 	for (int i = 0; i < 12; i++) {
	// 		ft::vector<int>::iterator it = test_myvector.begin();
	// 		std::vector<int>::iterator it2 = test_vector.begin();
	// 		for (; it != test_myvector.end() && it2 != test_vector.end(); it++, it2++)
	// 			std::cout << *it << " == " << *it2 << " | ";
	// 		std::cout << "\n";
	// 		test_myvector.erase(test_myvector.begin());
	// 		test_vector.erase(test_vector.begin());

	// 	}
	// }


	{
		std::cout << BN << "*********** REVERSE_ITERATORS TESTS ************" << BN;
		std::vector<int>	v;
		ft::vector<int>		v_bis;
		int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		v.insert(v.begin(), t, t + 10);
		v_bis.insert(v_bis.begin(), t, t + 10);

		std::cout << "v -->  ";
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << " ";
		std::cout << BN << "v_bis -->  ";
		for (int i = 0; i < 10; i++)
			std::cout << v_bis[i] << " ";
		std::cout << BN;
		std::cout << BN;
		std::cout << "v.rend() : " << *(v.rend().base()) << "\n";
		std::cout << "v.rbegin() : " << *(v.rbegin().base() - 1) << "\n";
		std::cout << "v_bis.rend() : " << *(v_bis.rend().base()) << "\n";
		std::cout << "v_bis.rbegin() : " << *(v_bis.rbegin().base() - 1) << "\n";


		std::cout << std::endl;
		std::cout << "testing reverse iterator from reverse iterator : " << "\n\n";
		typedef std::vector<int>::iterator	iter_type;
		typedef ft::vector<int>::iterator	ft_iter_type;


		std::reverse_iterator<iter_type> test(v.end());
		ft::reverse_iterator<ft_iter_type> test_bis(v_bis.end());
		std::cout << "test : " << *test << std::endl;
		std::cout << "test_bis : " << *test << std::endl;

		//test = v.rend() + 4;
		//std::cout << *test << " v.rend() + 4\n";
		test_bis = v_bis.rend() + 4;
		std::cout << *test_bis << " v_bis.rend() + 4\n";

		std::cout << "\n\n******FIN DU TEST******\n";
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
