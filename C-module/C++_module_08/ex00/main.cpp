#include "easyfind.hpp"


int main() {

	std::vector<int> v;
	v.reserve(100);

	for(int i = 0; i < 100; ++i)
		v.push_back(i);

	std::random_shuffle(v.begin(), v.end());

	int result = easyfind(v, 30);
	if(result == -1)
		std::cout << "No such item.";
	else
		std::cout << "Item found" << std::endl;
	return 0;
}