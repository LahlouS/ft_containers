#include <vector>
#include <iostream>


int main(void){
	std::vector<int> v;
	int t[10] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	v.insert(v.begin(), t, t + 10);

	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "rend() : " << *(v.rend().base()) << "\n";
	std::cout << "rbegin() : " << *(v.rbegin().base() - 1) << "\n";
	std::cout << std::endl;

	//std::cout << "testing reverse iterator from reverse iterator : " << "\n\n";
	//typedef std::vector<int>::iterator iter_type;
	//std::reverse_iterator<iter_type> test(v.end());

	//std::cout << "test : " << *test << std::endl;
	std::cout << "\n\n******FIN DU TEST******\n";
	return (0);
}

