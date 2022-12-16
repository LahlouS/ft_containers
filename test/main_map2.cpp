#include "map.hpp"
#include <map>
#include <iostream>


int main(void) {
	// ft::pair<int, int> p[12];

	// p[0] = ft::make_pair(1, 56);
	// p[1] = ft::make_pair(2, 57);
	// p[2] = ft::make_pair(3, 58);
	// p[3] = ft::make_pair(4, 59);
	// p[4] = ft::make_pair(5, 60);
	// p[5] = ft::make_pair(6, 61);
	// p[6] = ft::make_pair(7, 62);
	// p[7] = ft::make_pair(8, 63);
	// p[8] = ft::make_pair(9, 64);
	// p[9] = ft::make_pair(10, 65);
	// p[10] = ft::make_pair(11, 66);
	// p[11] = ft::make_pair(12, 67);

	// ft::map<int, int> mp(p, p + 12);
	// ft::map<int, int> cpy(p + 2, p + 5);

	// mp.printBT();
	// std::cout << "size of mp : " << mp.size() << BN;
	// cpy.printBT();
	// std::cout << "size of cpy : " << cpy.size() << BN;
	// cpy = mp;
	// std::cout << "size of cpy after taking mp: " << cpy.size() << " and checking empty() " << cpy.empty() << BN;
	// cpy.printBT();


	// std::cout << "mp[5] = " << mp[5] << BN;
	// mp[5] = 1999;
	// std::cout << "after doing [mp[5] = 1999] : mp[5] = " << mp[5] << BN;
	// std::cout << "size :" << mp.size() << BN;


	// try {
	// 	std::cout << mp.at(0) << " is mapped value at key 12\n";
	// } catch (std::exception & e) {
	// 	std::cout << e.what() << BN;
	// }

	// std::cout << BN << BN << "****************** testing the swap function :" << BN;
	// cpy.insert(ft::make_pair(1000, 0));
	// cpy.insert(ft::make_pair(2000, 0));
	// cpy.insert(ft::make_pair(3000, 0));
	// cpy.insert(ft::make_pair(-8000, 0));

	// std::cout << "printing both my map to check there differences :\nmp -->" << BN;
	// std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	// std::cout << "cpy -->\n";
	// std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();

	// mp.swap(cpy);

	// std::cout << "printing again after swap :\nmp -->" << BN;
	// std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	// std::cout << "cpy -->\n";
	// std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();


	// std::cout << "\n******************* end of the test *******************\n\n";
	// mp.clear();
	// cpy.clear();
	// std::cout << "print cpy after clear :\n";
	// cpy.printBT();
	// std::cout << "\nprint mp after clear :\n";
	// mp.printBT();

	// ft::map<int, int>::iterator itbeg = mp.begin();
	// ft::map<int, int>::iterator itend = mp.end();

	// for (; itbeg != itend;)
	// 	std::cout << "ca va casser sec!!!!!!!!!!!!\n";

	// std::cout << std::boolalpha;
	// std::cout << (mp.key_comp()).operator()(5, 10) << BN;

	// mp.insert(ft::make_pair(1045, 0));
	// std::cout << "finding stuff that does not exit : " << (--(mp.find(56)))->first << BN;
	// mp.insert(ft::make_pair(56, 0));
	// std::cout << "finding stuff that does exit : " << mp.find(56)->first << BN;

	// std::map<int, int> mpV;

	// mpV.insert(std::make_pair(1, 0));
	// mpV.insert(std::make_pair(2, 0));
	// mpV.insert(std::make_pair(3, 0));
	// mpV.insert(std::make_pair(4, 0));
	// mpV.insert(std::make_pair(5, 0));
	// mpV.insert(std::make_pair(6, 0));
	// mpV.insert(std::make_pair(7, 0));
	// mpV.insert(std::make_pair(8, 0));
	// if (mpV.lower_bound(15) == mpV.end())
	// 	std::cout << "Je commence a avoir un peu faim\n";
	// std::cout << "trying lower_bound that will never be false " << mpV.lower_bound(15)->first << BN;

	// ft::map<char,int> mymap;

	// mymap.insert(ft::make_pair('a', 0));
	// mymap.insert(ft::make_pair('b', 0));
	// mymap.insert(ft::make_pair('c', 0));

	// mymap['a'] = 10;
	// mymap['b'] = 20;
	// mymap['c'] = 30;

	// ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	// ret = mymap.equal_range('b');

	// std::cout << "lower bound points to: ";
	// std::cout << ret.first->first << " => " << ret.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << ret.second->first << " => " << ret.second->second << '\n';

	ft::map<int, int> n;
	ft::map<int, int> p;

	n.insert(ft::make_pair(1, 0));
	n.insert(ft::make_pair(2, 0));
	n.insert(ft::make_pair(3, 0));

	p.insert(ft::make_pair(8, 0));
	p.insert(ft::make_pair(9, 0));
	p.insert(ft::make_pair(10, 0));

	ft::swap(n, p);


	return (0);
}
