#include <vector>
#include "stack.hpp"
// #include <stack>
#include <iostream>

#define BN "\n"

int main(void){
	ft::stack<int> s;
	ft::stack<int> s2;

	for(int i = 0; i < 5; i++) {
		s.push(42 + i);
		s2.push(42 + i);
	}

	std::cout << std::boolalpha;
	std::cout << (s != s2) << BN;
	std::cout << (s == s2) << BN;
	std::cout << (s < s2) << BN;
	std::cout << (s <= s2) << BN;
	std::cout << (s > s2) << BN;
	std::cout << (s >= s2) << BN;

	std::cout << "printing the content of my stack" << BN;
	for(; !s.empty(); ) {
		std::cout << "s.top : " << s.top() << BN;
		s.pop();
	}


	return (0);
}

