#include <vector>
#include <iostream>

#define BN "\n"

int main(void){
	std::vector<int> v;

	std::vector<int> v2;

	int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int f[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 98};
	v.insert(v.begin(), t, t + 10);
	v2.insert(v2.begin(), f, f + 10);

	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << BN;


	for (int i = 0; i < 10; i++)
		std::cout << v2[i] << " ";
	std::cout << BN;

	v = v2;

	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << BN;

	return (0);
}

