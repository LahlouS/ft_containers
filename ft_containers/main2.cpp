#include <map>
#include <iostream>

#define BN "\n"

int main(void){
	std::pair<int, std::string> pair_test[3] = {std::make_pair<int, std::string>(85, "sacha"), std::make_pair<int, std::string>(68, "papa"), std::make_pair<int, std::string>(68, "armelle")};

	std::map<int, std::string> map_test(pair_test, pair_test + 3);

	for (std::map<int, std::string>::iterator it = map_test.begin(); it != map_test.end(); it++)
		std::cout << it->first << " : " << it->second << BN;
	std::cout << BN;

	return (0);
}

