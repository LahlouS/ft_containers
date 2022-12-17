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

int main(void) {
	ft::pair<int, int> p[12];

	p[0] = ft::make_pair(1, 56);
	p[1] = ft::make_pair(2, 57);
	p[2] = ft::make_pair(3, 58);
	p[3] = ft::make_pair(4, 59);
	p[4] = ft::make_pair(5, 60);
	p[5] = ft::make_pair(6, 61);
	p[6] = ft::make_pair(7, 62);
	p[7] = ft::make_pair(8, 63);
	p[8] = ft::make_pair(9, 64);
	p[9] = ft::make_pair(10, 65);
	p[10] = ft::make_pair(11, 66);
	p[11] = ft::make_pair(12, 67);

	ft::map<int, int> mp(p, p + 12);
	ft::map<int, int> cpy(p + 2, p + 5);

	// mp.printBT();
	std::cout << "size of mp : " << mp.size() << "\n";
	// cpy.printBT();
	std::cout << "size of cpy : " << cpy.size() << "\n";
	cpy = mp;
	std::cout << "size of cpy after taking mp: " << cpy.size() << " and checking empty() " << cpy.empty() << "\n";
	// cpy.printBT();


	std::cout << "mp[5] = " << mp[5] << "\n";
	mp[5] = 1999;
	std::cout << "after doing [mp[5] = 1999] : mp[5] = " << mp[5] << "\n";
	std::cout << "size :" << mp.size() << "\n";


	// try {
		// std::cout << mp.at(0) << " is mapped value at key 12\n";
	// } catch (std::exception & e) {
		// std::cout << e.what() << "\n";
	// }

	std::cout << "\n" << "\n" << "****************** testing the swap function :" << "\n";
	cpy.insert(ft::make_pair(1000, 0));
	cpy.insert(ft::make_pair(2000, 0));
	cpy.insert(ft::make_pair(3000, 0));
	cpy.insert(ft::make_pair(-8000, 0));

	std::cout << "printing both my map to check there differences :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();

	mp.swap(cpy);

	std::cout << "printing again after swap :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();


	std::cout << "\n******************* end of the test *******************\n\n";
	mp.clear();
	cpy.clear();
	ft::map<int, int>::iterator itbeg = mp.begin();
	ft::map<int, int>::iterator itend = mp.end();

	if (itbeg == itend)
		std::cout << "we enter here because (itbeg == itend) because we just clear !!\n";
	for (; itbeg != itend;)
		std::cout << "ca va casser sec!!!!!!!!!!!!\n";

	std::cout << std::boolalpha;
	std::cout << (mp.key_comp()).operator()(5, 10) << "\n";

	mp.insert(ft::make_pair(1045, 0));
	std::cout << "finding stuff that does not exit : " << (--(mp.find(56)))->first << "\n";
	mp.insert(ft::make_pair(56, 0));
	std::cout << "finding stuff that does exit : " << mp.find(56)->first << "\n";

	ft::map<char,int> mymap;

	mymap.insert(ft::make_pair('a', 0));
	mymap.insert(ft::make_pair('b', 0));
	mymap.insert(ft::make_pair('c', 0));

	std::cout << "initialising mymap with value = 0 : \n";

	std::cout << "mymap['a'] : " << mymap['a'] << "\n";
	std::cout << "mymap['b'] : " << mymap['b'] << "\n";
	std::cout << "mymap['c'] : " << mymap['c'] << "\n";

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	std::cout << "now after chamging value this way ( mymap['x'] = X ) :\n";
	std::cout << "mymap['a'] : " << mymap['a'] << "\n";
	std::cout << "mymap['b'] : " << mymap['b'] << "\n";
	std::cout << "mymap['c'] : " << mymap['c'] << "\n";


	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	ft::map<int, int> y;
	ft::map<int, int> z;


	std::cout << "************************ testing swap function : **************************** \n\n";

	y.insert(ft::make_pair(1, 56));
	y.insert(ft::make_pair(2, 57));
	y.insert(ft::make_pair(3, 58));

	z.insert(ft::make_pair(8, 45));
	z.insert(ft::make_pair(9, 46));
	z.insert(ft::make_pair(10, 47));

	std::cout << "keys inserted for z : [8, 9, 10]\n" << z[8] << " " << z[9] << " " << z[10]  << " " << "\n";
	std::cout << "keys inserted for y : [1, 2, 3] -> " << y[1]  << " " << y[2]  << " " << y[3]  << " " << "\n";

	ft::map<int, int>::iterator rit1 = y.begin();
	ft::map<int, int>::iterator rit2 = z.begin();

	ft::swap(y, z);

	std::cout << "keys inserted for z : [8, 9, 10] ->" << z[8]  << " " << z[9]  << " " << z[10]  << " " << "\n";
	std::cout << "keys inserted for y : [1, 2, 3] -> " << y[1]  << " " << y[2]  << " " << y[3]  << " " << "\n";

	std::cout << "\nand testing now with iterators\n\n";


	for (; rit1 != z.end(); rit1++)
		std::cout << "with syntax (*rit).first " << (*rit1).first << "\n";
	std::cout << "---------------------------------------------\n";
	for (; rit2 != y.end(); rit2++)
		std::cout << "with syntax (*rit).first " << (*rit2).first << "\n";

	return (0);
}
