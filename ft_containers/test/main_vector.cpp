#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>
#if REAL //CREATE A REAL STL EXAMPLE

	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

int main( void )
{
	ft::vector<int> 			test(5, 42);
	ft::vector<int> 			test_range(test.begin(), test.end());
	ft::vector<int>::iterator	it = test.begin();
	ft::vector<int>::iterator	it_range = test_range.begin();
	int i = 0;
	std::cout << "\n" << "***testing iterators loop and wellness of initilisation (range constructor and value constructor)*** : " << "\n" << "\n";
	std::cout << "while (it != test.end()) { " << "\n" << "\n";
	while (it != test.end()) {
		std::cout << "value " << i++ << " : " << *it++ << " == " << *it_range++ << "\n";
	}
	if (it == test.end())
		std::cout << "\n" << "it == test.end()\n\n";
	std::cout << "}\n\n--> for (int i = 0; i < 5; i++) std::cout << *(it + i) {\n";

	it = test.begin();
	for (int i = 0; i < 5; i++)
		std::cout << *(it + i) << " ";
	std::cout << "\n";

	std::cout << "}\n\n--> and know testing the '-' operator with it = test.end() - 1 {\n";

	it = (test.end() - 1);
	for (int i = 0; i != 5; i++)
		std::cout << *(it - i) << " ";
	std::cout << "\n";

	std::cout << "}" << "\n" << "\n";

	std::cout << "\n\n--> it += / -= 4 {" << "\n";
	std::cout << *(it -= 4) << "\n";
	std:: cout << *(it += 4) << "\n";
	std::cout << "}\n";

	std::cout << "***" << "\n" << "\n";

	std::cout << "***CHAR_TRAITS TEST*** :" << "\n" << "\n" <<"sizeof(ft::iterator_traits<long *>::value_type) : " << sizeof(ft::iterator_traits<long *>::value_type) << "\n";
	if (typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test VRAI" << "\n";
	else
		std::cout << "[ft::iterator_traits<long *>::iterator_category] : test FAUX" << "\n";
	std::cout << "***" << "\n";

	std::cout << "***TESTING IS_INTEGRAL TEMPLATE***" << "\n" << "\n";
	std::cout << std::boolalpha;
	std::cout << "char : " << ft::is_integral<char>::value << std::endl;
	std::cout << "const char : " << ft::is_integral<const char >::value << std::endl;
	std::cout << "const volatile int : " << ft::is_integral<const volatile int>::value << std::endl;
	std::cout << "float : " << ft::is_integral<float>::value << "\n";
	std::cout << "int : " << ft::is_integral<int>::value << "\n";
	std::cout << "ft::vector<int> : " << ft::is_integral<ft::vector<int> >::value << "\n";
	std::cout << "ft::vector<int>::iterator : " << ft::is_integral<ft::vector<int>::iterator>::value << "\n";
	std::cout << "short : " << ft::is_integral<short>::value << "\n";
	std::cout << "***" << "\n";
	{
		std::cout << "testing iterators attributtes (const / non const)" << "\n";
		ft::vector<int> test(5, 12);
		ft::vector<int>::iterator it = test.begin();

		*it = 16;
		*(it + 1) = 42;

		while (it != test.end())
			std::cout << *it++ << "\n";

	}

	{
		std::cout << "\n" << "***  TESTING INSERT FUNCTION  ***" << "\n";
		ft::vector<int> test_insert;

		std::cout << "Printing insert return value : " << "\n";
		std::cout << *(test_insert.insert(test_insert.begin(), 42)) << "\n";
		std::cout << *(test_insert.insert(test_insert.begin(), 56)) << "\n";
		std::cout << *(test_insert.insert(test_insert.begin() + 1, 489)) << "\n";
		std::cout << *(test_insert.insert(test_insert.begin() + 2, 1)) << "\n";
		std::cout << *(test_insert.insert(test_insert.begin(), 506)) << "\n";
		std::cout << *(test_insert.insert(test_insert.end(), 420)) << "\n";
		std::cout << *(test_insert.insert(test_insert.end(), 560)) << "\n";
		std::cout << *(test_insert.insert(test_insert.end(), 4890)) << "\n";
		std::cout << *(test_insert.insert(test_insert.end(), 10)) << "\n";
		std::cout << *(test_insert.insert(test_insert.end(), 5060)) << "\n";

		std::cout << "\n" << "printing vector attributes :" << "\n" << "\n";
		for (ft::vector<int>::iterator	it = test_insert.begin(); it != test_insert.end(); it++)
			std::cout << *it << " ";
		std::cout << "\n";

		std::cout << "\n***\n";
	}

	{
		ft::vector<int> test_myvector;

		std::cout << "testing with multiple entry" << "\n" << "--> insert(vec.begin(), 12, 42)" << "\n";
		test_myvector.insert(test_myvector.begin(), 12, 52);
		std::cout << "test_myvector[i]" << "\n";
		for (int i = 0; i < 12; i++) {
			std::cout << "--> " << test_myvector[i] << "\n";
		}
		std::cout << "\n" << "-->testing erase function :" << "\n";
		for (int i = 0; i < 12; i++) {
			ft::vector<int>::iterator it = test_myvector.begin();
			for (; it != test_myvector.end(); it++)
				std::cout << *it << " ";
			std::cout << "\n";
			test_myvector.erase(test_myvector.begin());
		}
	}

	{
		std::cout << "\n" << "*********** REVERSE_ITERATORS TESTS ************" << "\n";
		std::vector<int>	v;
		ft::vector<int>		v_bis;
		int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		v.insert(v.begin(), t, t + 10);
		v_bis.insert(v_bis.begin(), t, t + 10);

		std::cout << "v -->  ";
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << " ";
		std::cout << "\n" << "v_bis -->  ";
		for (int i = 0; i < 10; i++)
			std::cout << v_bis[i] << " ";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "v.rend() : " << *(v.rend().base()) << "\n";
		std::cout << "v.rbegin() : " << *(v.rbegin().base() - 1) << "\n";
		std::cout << "v_bis.rend() : " << *(v_bis.rend().base()) << "\n";
		std::cout << "v_bis.rbegin() : " << *(v_bis.rbegin().base() - 1) << "\n";


		std::cout << std::endl;
		std::cout << "testing reverse iterator from reverse iterator : " << "\n\n";
		typedef std::vector<int>::iterator	iter_type;
		typedef ft::vector<int>::iterator	ft_iter_type;


		std::reverse_iterator<iter_type> test;
		ft::reverse_iterator<ft_iter_type> test_bis;

		std::cout << "\n" << "--> My vector:\n";

		test_bis = v_bis.rbegin();
		std::cout << "test_bis[i] :\n";
		for (size_t i = 0; i < 10; i++)
			std::cout << test_bis[i] << " ";
		std::cout << "\n";
		std::cout << "*test_bis++ :\n";
		for (; test_bis != v_bis.rend();)
			std::cout << *test_bis++ << " ";

		std::cout << "\n" << "--> the real vector :\n";
		test = v.rbegin();
		std::cout << "test[i] :\n";
		for (size_t i = 0; i < 10; i++)
			std::cout << test[i] << " ";
		std::cout << "\n";
		std::cout << "*test++ :\n";
		for (; test != v.rend();)
			std::cout << *test++ << " ";

		std::cout << "\n\n******FIN DU TEST******\n";
	}

	{
	std::vector<int> test;
	std::vector<int>::iterator it = test.end();

	test.insert(it, 1, 25);
	test.insert(test.end(), 1, 35);
	test.insert(test.end(), 1, 45);

	std::cout << "ici mon test : " << test[0] << "\n";
	std::cout << "ici mon test : " << test[1] << "\n";
	std::cout << "ici mon test : " << test[2] << "\n";
	std::cout << "\n";
	}

{
	std::cout << "TESTING _capacity FUNCTIONS : " << "\n" << "\n";
		std::vector<int>	v;
		ft::vector<int>		v_bis;
		int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		v.insert(v.begin(), t, t + 10);
		v_bis.insert(v_bis.begin(), t, t + 10);

		std::cout << "v - v_bis" << "\n";
		for (size_t i = 0; i < 10; i++)
			std::cout << " " << v[i] << " - " << v_bis[i] << "\n";
		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << "\n";
		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << "\n";

		std::cout << "\n\n\nNow testing the resize function with smaller size (5) : \n";
		v.resize(5);
		v_bis.resize(5);
		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << "\n";
		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << "\n";
		std::cout << "v - v_bis" << "\n";
		for (size_t i = 0; i < v_bis.size(); i++)
			std::cout << " " << v[i] << " - " << v_bis[i] << "\n";
		std::cout << "\n\n\nNow testing the resize function with greater size (10) with init at 42 : \n";
		v.resize(10, 42);
		v_bis.resize(10, 42);
		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << "\n";
		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << "\n";
		std::cout << "v - v_bis" << "\n";
		for (size_t i = 0; i < v_bis.size(); i++)
			std::cout << " " << v[i] << " - " << v_bis[i] << "\n";

		std::cout << "\n\n///////////////////////////////////\n\n";
		// v_bis.print();
		std::cout << "\n\n/////////////////\n\n";

		std::cout << "\n\n\nNow testing the resize function with greater size AND beyond capacity (40) with init at 42 : \n";
		v.resize(40, 42);
		v_bis.resize(40, 42);
		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << "\n";
		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << "\n";
		std::cout << "v - v_bis" << "\n";
		for (size_t i = 0; i < v_bis.size(); i++)
			std::cout << " " << v[i] << " - " << v_bis[i] << "\n";

		std::cout << "\n\n\nNow testing the resize function with fucked up things : \n";
		try {
			//v.resize(-5, 42);
			v_bis.resize(-5, 42);
		} catch (std::exception & e) {
			std::cout << e.what();
		}

		std::cout << "\nSIZE() --> size v : " << v.size() << "size v_bis : " << v_bis.size() << "\n";
		std::cout << "\nMAX_SIZE() --> max_size v : " << v.max_size() << "max_size v_bis : " << v_bis.max_size() << "\n";
		std::cout << "v - v_bis" << "\n";
		for (size_t i = 0; i < v_bis.size(); i++)
			std::cout << " " << v[i] << " - " << v_bis[i] << "\n";

	}

	{
		std::vector<int>	v;
		ft::vector<int>		v_bis;

		if (v.empty() && v_bis.empty())
			std::cout << "empty() seems to work 1/2\n\n";
		int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		v.insert(v.begin(), t, t + 10);
		v_bis.insert(v_bis.begin(), t, t + 10);
		if (!v.empty() && !v_bis.empty())
			std::cout << "empty() seems to work 2/2\n\n";

		// std::cout << v.capacity() << "----------------------------- > official vector capacity\n";
		// std::cout << v_bis.capacity() << "-------------------------- > my vector capacity\n";
		std::cout << "\n";
		v.reserve(50);
		v_bis.reserve(50);
		std::cout << v.capacity() << " after reserving 50\n";
		std::cout << v_bis.capacity() << " after reserving 50\n";

		ft::vector<int>::iterator it_bis = v_bis.begin();
		std::vector<int>::iterator it = v.begin();
		std::cout << "printing to see if everything is all right :\n*it++  -  " "*it_bis++" << "\n";
		for (int i = 0; i < 10; i++)
			std::cout << *it++ << "  -  " << *it_bis++ << "\n";

		v_bis.shrink_to_fit();
		it_bis = v_bis.begin();
		std::cout << "\n" << "and know after shrink to fit call\n*it++  -  " "*it_bis++" << "\n";
		for (int i = 0; i < 10; i++)
			std::cout << *it_bis++ << "\n";

		std::cout << v_bis.capacity() << " my vector capacity\n";


		std::cout << "\n";
	}
	{
		std::cout << "****  TESTING ACESS ELEMENTS  ****" << "\n" << "\n";
			std::vector<int>	v(5);
			ft::vector<int>		v_bis(5);

			try {
				std::cout << "normal utilisation :" << v.at(0) << " " << v_bis.at(0) << "\n";
				//v.at(12);
			} catch (std::exception const & e) {
				std::cout << e.what();
			}
		std::cout << "v.capacity() : " << v.capacity() << "\n";
		std::cout << "v_bis.capacity() : " << v_bis.capacity() << "\n";
	}

	{
		std::cout << "****  TESTING =OPERATOR ****" << "\n" << "\n";
		char c[] = {78, 89, 45, 56, 12, 23};

		ft::vector<int>	test(c, c + 6);
		ft::vector<int> myvector = test;
		std::cout << "AUCUN PB\n\n";

		std::cout << "\n" << "\n";
		for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << " " << myvector[i] << "\n";
	}

	{
		std::cout << "********  TESTING ACCESS ELEMENTS ************" << "\n" << "\n";

		std::string strs[3];

		strs[0] = "test";
		strs[1] = "test1";
		strs[2] = "test2";

		std::vector<std::string>	v(strs, strs + 3);
		ft::vector<std::string>	vbis(strs, strs + 3);

		std::cout << "     v  --  vbis\n";
		for (size_t i = 0; i < vbis.size(); i++)
			std::cout << "   " << v[i] << " - " << vbis[i] << "\n";
		std::cout << "\n";
		std::cout << "testing front() function :" << "\n";
		std::cout << "v.front() : " << v.front() << "\n";
		std::cout << "vbis.front() : " << vbis.front() << "\n" << "\n";

		std::cout << "testing back() function :" << "\n";
		std::cout << "v.back() : " << v.back() << "\n";
		std::cout << "vbis.back() : " << vbis.back() << "\n" << "\n";

		// std::cout << "testing data() function :" << "\n";
		// std::cout << "v.data() : " << v.data() << "\n";
		// std::cout << "vbis.data() : " << vbis.data() << "\n";

		std::cout << "\n\n********  FIN DU TEST ************" << "\n" << "\n";

		std::cout << "********  TESTING MODIFIERS ELEMENTS ************" << "\n" << "\n";

		std::cout << "testing push_back() function :" << "\n";
		v.push_back("NOUVELLE STR");
		vbis.push_back("NOUVELLE STR");
		std::cout << "v.back()    (after push_back(\"NOUVELLE STR\")): " << v.back() << "\n";
		std::cout << "vbis.back() (after push_back(\"NOUVELLE STR\")): " << vbis.back() << "\n" << "\n";

		std::cout << "testing pop_back() function :" << "\n";
		v.pop_back();
		vbis.pop_back();
		std::cout << "v.back()    (after pop_back): " << v.back() << "\n";
		std::cout << "vbis.back() (after pop_back): " << vbis.back() << "\n" << "\n";
		v.pop_back();
		v.pop_back();
		v.pop_back();
		vbis.pop_back();
		vbis.pop_back();
		vbis.pop_back();
		std::cout << "testing size after pop_back() everything : \nv ->" << v.size() << "\n" << "vbis->" << vbis.size() << "\n" << "\n";
		v.assign(5, "original");
		vbis.assign(5, "original");
		std::cout << "testing swap() function :" << "\n";
		std::vector<std::string> v2(5, "swap");
		ft::vector<std::string> vbis2(5, "swap");

		v.swap(v2);
		vbis.swap(vbis2);

		std::cout << "testing swap() and assign function : " << "\n";
		std::cout << "v[i]" << " | " << "vbis[i]" << "\n";
		for (size_t i = 0; i < vbis.size(); i++){
			std::cout << v[i] << " " << vbis[i] << "\n";
		}
		std::cout << "\n" << "v2[i]" << " | " << "vbis2[i]" << "\n";
		for (size_t i = 0; i < vbis2.size(); i++){
			std::cout << v2[i] << " " << vbis2[i] << "\n";
		}

		std::cout << "\n\n******FIN DU TEST******\n";
		v.clear();
		v2.clear();
		vbis.clear();
		vbis2.clear();

		std::cout << "size after all cleared : " << (v.size() + v2.size() + vbis.size() + vbis2.size()) << "\n";

	}

	{
		std::cout << "***  TESTING VECTOR RELATIONAL OPERATOR   ***" << "\n" << "\n";

		ft::vector<int> v;
		ft::vector<int> v2;

		int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int f[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
		v.insert(v.begin(), t, t + 10);
		v2.insert(v2.begin(), f, f + 10);

		std::cout << "v" << "  " << "v2" << "\n";
		std::cout << "--" << "  " << "--" << "\n";
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << "  " << v2[i] << "\n";
		std::cout << "\n";

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

		std::cout << std::boolalpha << ft::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) << "\n";

		std::cout << "**********  FIN DU TEST  *******************" << "\n" << "\n";

	}
 	return (0);
}
