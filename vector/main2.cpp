#include <vector>
#include <iostream>

#define BN "\n"

int main(void){
	std::vector<int> v;
	int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	v.insert(v.begin(), t, t + 10);

	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << BN;
	std::cout << BN;

	v.insert(v.begin(), t + 2, t + 4);

	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << BN;
	std::cout << BN;

	v.assign(5, 42);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << BN;
	std::cout << BN;

	v.emplace(v.begin(), 12);
	return (0);
}

