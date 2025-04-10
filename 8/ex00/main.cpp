#include "easyfind.hpp"


int main() {
	
	std::vector<int>	vector;
	std::deque<int>		deque;
	std::list<int>		list;

	for (size_t i = 0; i < 5; i++)
		vector.push_back(i);

	for (size_t i = 0; i < 5; i++)
		deque.push_back(i);

	for (size_t i = 0; i < 5; i++)
		list.push_back(i);

	std::cout << "(vector, 2 ): " << easyfind(vector, 2) << std::endl;
	std::cout << "(vector, 2, func find ): " << easyfind(vector, 2, 1) << std::endl;
	std::cout << "(deque, 0 ): " << easyfind(deque, 0) << std::endl;
	std::cout << "(deque, 0, func find ): " << easyfind(deque, 0, 1) << std::endl;
	std::cout << "(list, 5 ): " << easyfind(list, 5) << std::endl;
	std::cout << "(list, 5, func find ): " << easyfind(list, 5, 1) << std::endl;

	return 0;
}
