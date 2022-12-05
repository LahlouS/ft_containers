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

	// {
		// std::cout << BN << "*********** REVERSE_ITERATORS TESTS ************" << BN;
		// std::vector<int>	v;
		// ft::vector<int>		v_bis;
		// int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		// v.insert(v.begin(), t, t + 10);
		// v_bis.insert(v_bis.begin(), t, t + 10);

		// std::cout << "v -->  ";
		// for (int i = 0; i < 10; i++)
			// std::cout << v[i] << " ";
		// std::cout << BN << "v_bis -->  ";
		// for (int i = 0; i < 10; i++)
			// std::cout << v_bis[i] << " ";
		// std::cout << BN;
		// std::cout << BN;
		// std::cout << "v.rend() : " << *(v.rend().base()) << "\n";
		// std::cout << "v.rbegin() : " << *(v.rbegin().base() - 1) << "\n";
		// std::cout << "v_bis.rend() : " << *(v_bis.rend().base()) << "\n";
		// std::cout << "v_bis.rbegin() : " << *(v_bis.rbegin().base() - 1) << "\n";


		// std::cout << std::endl;
		// std::cout << "testing reverse iterator from reverse iterator : " << "\n\n";
		// typedef std::vector<int>::iterator	iter_type;
		// typedef ft::vector<int>::iterator	ft_iter_type;


		// std::reverse_iterator<iter_type> test;
		// ft::reverse_iterator<ft_iter_type> test_bis;

		// std::cout << BN << "--> My vector:\n";

		// test_bis = v_bis.rbegin();
		// std::cout << "test_bis[i] :\n";
		// for (size_t i = 0; i < 10; i++)
			// std::cout << test_bis[i] << " ";
		// std::cout << BN;
		// std::cout << "*test_bis++ :\n";
		// for (; test_bis != v_bis.rend();)
			// std::cout << *test_bis++ << " ";

		// std::cout << BN << "--> the real vector :\n";
		// test = v.rbegin();
		// std::cout << "test[i] :\n";
		// for (size_t i = 0; i < 10; i++)
			// std::cout << test[i] << " ";
		// std::cout << BN;
		// std::cout << "*test++ :\n";
		// for (; test != v.rend();)
			// std::cout << *test++ << " ";

		// std::cout << "\n\n******FIN DU TEST******\n";
	// }
	// return (0);
// }


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

// {
// 	std::cout << "TESTING _capacity FUNCTIONS : " << BN << BN;
// 		std::vector<int>	v;
// 		ft::vector<int>		v_bis;
// 		int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 		v.insert(v.begin(), t, t + 10);
// 		v_bis.insert(v_bis.begin(), t, t + 10);

// 		std::cout << "v - v_bis" << BN;
// 		for (size_t i = 0; i < 10; i++)
// 			std::cout << " " << v[i] << " - " << v_bis[i] << BN;
// 		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << BN;
// 		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << BN;

// 		std::cout << "\n\n\nNow testing the resize function with smaller size (5) : \n";
// 		v.resize(5);
// 		v_bis.resize(5);
// 		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << BN;
// 		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << BN;
// 		std::cout << "v - v_bis" << BN;
// 		for (size_t i = 0; i < v_bis.size(); i++)
// 			std::cout << " " << v[i] << " - " << v_bis[i] << BN;
// 		std::cout << "\n\n\nNow testing the resize function with greater size (10) with init at 42 : \n";
// 		v.resize(10, 42);
// 		v_bis.resize(10, 42);
// 		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << BN;
// 		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << BN;
// 		std::cout << "v - v_bis" << BN;
// 		for (size_t i = 0; i < v_bis.size(); i++)
// 			std::cout << " " << v[i] << " - " << v_bis[i] << BN;

// 		std::cout << "\n\n///////////////////////////////////\n\n";
// 		v_bis.print();
// 		std::cout << "\n\n/////////////////\n\n";

// 		std::cout << "\n\n\nNow testing the resize function with greater size AND beyond capacity (40) with init at 42 : \n";
// 		v.resize(40, 42);
// 		v_bis.resize(40, 42);
// 		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << BN;
// 		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << BN;
// 		std::cout << "v - v_bis" << BN;
// 		for (size_t i = 0; i < v_bis.size(); i++)
// 			std::cout << " " << v[i] << " - " << v_bis[i] << BN;

// 		std::cout << "\n\n\nNow testing the resize function with fucked up things : \n";
// 		try {
// 			//v.resize(-5, 42);
// 			v_bis.resize(-5, 42);
// 		} catch (std::exception & e) {
// 			std::cout << e.what();
// 		}

// 		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << BN;
// 		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << BN;
// 		std::cout << "v - v_bis" << BN;
// 		for (size_t i = 0; i < v_bis.size(); i++)
// 			std::cout << " " << v[i] << " - " << v_bis[i] << BN;

// 	}

	// {
	// 	std::vector<int>	v;
	// 	ft::vector<int>		v_bis;

	// 	if (v.empty() && v_bis.empty())
	// 		std::cout << "empty() seems to work 1/2\n\n";
	// 	int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 	v.insert(v.begin(), t, t + 10);
	// 	v_bis.insert(v_bis.begin(), t, t + 10);
	// 	if (!v.empty() && !v_bis.empty())
	// 		std::cout << "empty() seems to work 2/2\n\n";

	// 	std::cout << v.capacity() << "official vector capacity\n";
	// 	std::cout << v_bis.capacity() << "my vector capacity\n";
	// 	std::cout << BN;
	// 	v.reserve(50);
	// 	v_bis.reserve(50);
	// 	std::cout << v.capacity() << " after reserving 50\n";
	// 	std::cout << v_bis.capacity() << " after reserving 50\n";

	// 	ft::vector<int>::iterator it_bis = v_bis.begin();
	// 	std::vector<int>::iterator it = v.begin();
	// 	std::cout << "printing to see if everything is all right :\n*it++  -  " "*it_bis++" << BN;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << *it++ << "  -  " << *it_bis++ << BN;

	// 	v_bis.shrink_to_fit();
	// 	it_bis = v_bis.begin();
	// 	std::cout << BN << "and know after shrink to fit call\n*it++  -  " "*it_bis++" << BN;
	// 	for (int i = 0; i < 10; i++)
	// 		std::cout << *it_bis++ << BN;

	// 	std::cout << v_bis.capacity() << " my vector capacity\n";


	// 	std::cout << BN;
	// }
	// {
	// 	std::cout << "****  TESTING ACESS ELEMENTS  ****" << BN << BN;
	// 		std::vector<int>	v(5);
	// 		ft::vector<int>		v_bis(5);

	// 		try {
	// 			std::cout << "normal utilisation :" << v.at(0) << " " << v_bis.at(0) << BN;
	// 			//v.at(12);
	// 		} catch (std::exception const & e) {
	// 			std::cout << e.what();
	// 		}
	// 	std::cout << "v.capacity() : " << v.capacity() << BN;
	// 	std::cout << "v_bis.capacity() : " << v_bis.capacity() << BN;
	// }

	// {
	// 	std::cout << "****  TESTING =OPERATOR ****" << BN << BN;
	// 	char c[] = {78, 89, 45, 56, 12, 23};

	// 	ft::vector<int>	test(c, c + 6);
	// 	ft::vector<int> myvector = test;
	// 	std::cout << "AUCUN PB\n\n";

	// 	std::cout << BN << BN;
	// 	test.print();
	// 	myvector.print();
	// }

	// {
	// 	std::cout << "********  TESTING ACCESS ELEMENTS ************" << BN << BN;

	// 	std::string strs[3];

	// 	strs[0] = "test";
	// 	strs[1] = "test1";
	// 	strs[2] = "test2";

	// 	std::vector<std::string>	v(strs, strs + 3);
	// 	ft::vector<std::string>	vbis(strs, strs + 3);

	// 	std::cout << "     v  --  vbis\n";
	// 	for (size_t i = 0; i < vbis.size(); i++)
	// 		std::cout << "   " << v[i] << " - " << vbis[i] << BN;
	// 	std::cout << BN;
	// 	std::cout << "testing front() function :" << BN;
	// 	std::cout << "v.front() : " << v.front() << BN;
	// 	std::cout << "vbis.front() : " << vbis.front() << BN << BN;

	// 	std::cout << "testing back() function :" << BN;
	// 	std::cout << "v.back() : " << v.back() << BN;
	// 	std::cout << "vbis.back() : " << vbis.back() << BN << BN;

	// 	std::cout << "testing data() function :" << BN;
	// 	std::cout << "v.data() : " << v.data() << BN;
	// 	std::cout << "vbis.data() : " << vbis.data() << BN;

	// 	std::cout << "\n\n********  FIN DU TEST ************" << BN << BN;

	// 	std::cout << "********  TESTING MODIFIERS ELEMENTS ************" << BN << BN;

	// 	std::cout << "testing push_back() function :" << BN;
	// 	v.push_back("NOUVELLE STR");
	// 	vbis.push_back("NOUVELLE STR");
	// 	std::cout << "v.back()    (after push_back(\"NOUVELLE STR\")): " << v.back() << BN;
	// 	std::cout << "vbis.back() (after push_back(\"NOUVELLE STR\")): " << vbis.back() << BN << BN;

	// 	std::cout << "testing pop_back() function :" << BN;
	// 	v.pop_back();
	// 	vbis.pop_back();
	// 	std::cout << "v.back()    (after pop_back): " << v.back() << BN;
	// 	std::cout << "vbis.back() (after pop_back): " << vbis.back() << BN << BN;
	// 	v.pop_back();
	// 	v.pop_back();
	// 	v.pop_back();
	// 	vbis.pop_back();
	// 	vbis.pop_back();
	// 	vbis.pop_back();
	// 	std::cout << "testing size after pop_back() everything : \nv ->" << v.size() << BN << "vbis->" << vbis.size() << BN << BN;
	// 	v.assign(5, "original");
	// 	vbis.assign(5, "original");
	// 	std::cout << "testing swap() function :" << BN;
	// 	std::vector<std::string> v2(5, "swap");
	// 	ft::vector<std::string> vbis2(5, "swap");

	// 	v.swap(v2);
	// 	vbis.swap(vbis2);

	// 	std::cout << "testing swap() and assign function : " << BN;
	// 	std::cout << "v[i]" << " | " << "vbis[i]" << BN;
	// 	for (size_t i = 0; i < vbis.size(); i++){
	// 		std::cout << v[i] << " " << vbis[i] << BN;
	// 	}
	// 	std::cout << BN << "v2[i]" << " | " << "vbis2[i]" << BN;
	// 	for (size_t i = 0; i < vbis2.size(); i++){
	// 		std::cout << v2[i] << " " << vbis2[i] << BN;
	// 	}

	// 	std::cout << "\n\n******FIN DU TEST******\n";
	// 	v.clear();
	// 	v2.clear();
	// 	vbis.clear();
	// 	vbis2.clear();

	// 	std::cout << "size after all cleared : " << (v.size() + v2.size() + vbis.size() + vbis2.size()) << BN;

	// }

	{
		std::cout << "***  TESTING VECTOR RELATIONAL OPERATOR   ***" << BN << BN;

		ft::vector<int> v;
		ft::vector<int> v2;

		int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int f[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
		v.insert(v.begin(), t, t + 10);
		v2.insert(v2.begin(), f, f + 10);

		std::cout << "v" << "  " << "v2" << BN;
		std::cout << "--" << "  " << "--" << BN;
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << "  " << v2[i] << BN;
		std::cout << BN;

		if (v < v2)
			std::cout << "v < v2 : true\n";
		else
			std::cout << "v < v2 : false\n";

		if (v > v2)
			std::cout << "v > v2 : true\n";
		else
			std::cout << "v > v2 : false\n";

		if (v == v2)
			std::cout << "v == v2 : true\n";
		else
			std::cout << "v == v2 : false\n";

		if (v != v2)
			std::cout << "v != v2 : true\n";
		else
			std::cout << "v != v2 : false\n";

		if (v <= v2)
			std::cout << "v <= v2 : true\n";
		else
			std::cout << "v <= v2 : false\n";

		if (v >= v2)
			std::cout << "v >= v2 : true\n";
		else
			std::cout << "v >= v2 : false\n";

		std::cout << std::boolalpha << ft::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end());
		std::cout << "**********  FIN DU TEST  *******************" << BN << BN;

	}
 	return (0);
}
