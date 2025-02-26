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

	easyfind(vector, 2);
	easyfind(deque, 0);
	easyfind(list, 5);

	easyfind(vector, 2, 1);
	easyfind(deque, 0, 1);
	easyfind(list, 5, 1);

	return 0;
}
