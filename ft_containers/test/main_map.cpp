#include <iostream>
#include <string>
#include <deque>
#if REAL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

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

	ft::map<int, int>::const_reverse_iterator rit = test.rbegin();

	std::cout << "\n";
	while (rit != test.rend()) {
		std::cout << rit->first << "\t";
		rit++;
	}
	std::cout << "\n";
	rit--;

	// rit->second = 89; // will not compile while iterators are const_reverse
	std::cout << "\n";
	while (rit != test.rbegin()) {
		std::cout << rit->second << "\t";
		rit--;
	}
	std::cout << "\n" << "\n";
	std::cout << "some test on different insert functions : " << "\n";
	std::cout << "first to last iterators insertion :\n";
	ft::map<int, int> test2;

	test2.insert(test.begin(), test.end());

	ft::map<int, int>::iterator it2 = test2.begin();


	for (; it2 != test2.end(); it2++) {
		std::cout << it2->first << "\t";
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "check return value of  'pair<iterator,bool> insert (const value_type& val)' :\n";

	std::cout << "test2.insert(ft::make_pair(788456, 0)).second -> " << test2.insert(ft::make_pair(788456, 0)).second << "\n";

	std::cout << "test2.insert(ft::make_pair(788456, 0)).first->first -> " << test2.insert(ft::make_pair(788456, 0)).first->first << "\n" << "\n";

	std::cout << "same but with a key_value that already exist : \n";
	std::cout << "test2.insert(ft::make_pair(100, 0)).second -> " << test2.insert(ft::make_pair(100, 0)).second << "\n";

	std::cout << "test2.insert(ft::make_pair(100, 0)).first->first -> " << test2.insert(ft::make_pair(100, 0)).first->first << "\n";

	std::cout << "Now printing all values to be sure we are all good :\n";

	it2 = test2.begin();

	for (; it2 != test2.end(); it2++)
		std::cout << it2->first << "\t" << "\n";
	std::cout << "\n";

	std::cout << "\n\nNow testing the function that start with given position iterator :\n";
	std::cout << test2.size() << " size\n";
	std::cout << "test2.insert(it2, std::make_pair(899000, 0)) : " << test2.insert(it2, ft::make_pair(899000, 0))->first << "\n";
	std::cout << test2.size() << " size\n";

	std::cout << "test2.insert(it2, std::make_pair(53, 0)) : " << test2.insert(test2.begin(), ft::make_pair(53, 0))->first << "\n";
	std::cout << test2.size() << " size\n";


	it2 = test.begin();

	std::cout << "Now printing all values to be sure we are all good :\n";
	for (; it2 != test.end(); it2++)
		std::cout << it2->first << "\t";
	std::cout << "\n";
	std::cout << "\n" << test.size() << " size\n";

	std::cout << "***************** Now testing erase function :********************\n";
	std::cout << test.size() << " la size avant le erase [test2]" << "\n";
	test.erase(test.begin(), --(--test.end()));
	std::cout << test.size() << " is size after erasing all [test2]\n";

	/* ********************** EXEMPLE TO PRINT THE TREE ************************/
		//test.printBT();
	std::cout << "\n" << "\n";

	{
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

		std::cout << "----------- > size : " << test.size();

		/* ********************** EXEMPLE TO PRINT THE TREE ************************/
		// test.printBT();

		std::cout << "\n\nbefore deletion : \n";

		std::cout << "\n\n****after deletion****" << "\n";
		test.erase(56);
		test.erase(23);
		test.erase(15);
		test.erase(66);
		test.erase(12);
		test.erase(1);
		test.erase(32);
		test.erase(9);
		test.erase(89);
		test.erase(7);
		test.erase(4);
		test.erase(100);
		test.erase(1245);

		/* ********************** EXEMPLE TO PRINT THE TREE ************************/
		// test.printBT();
		test.erase(23);

		ft::map<int, int>::iterator it = test.end();
		--it;
		std::cout << "it->first : " << it->first << "\n" << "\n";
		std::cout << "it-- -->\n\n";
		for (;it != test.begin();) {
			std::cout << it->first << "\t";
			--it;
		}
		std::cout << "\n";
		std::cout << "it->first : " << it->first << "\n";
		--it;
		it++;
		it++;
		it++;
		it++;
		it++;
		std::cout << "LA ->> " << it->first << "\n";
	}

	return (0);
}
