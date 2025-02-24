#include <iostream>
#include "Array.tpp"


int main() {
	
	Array<int> n(5);
	Array<char> c(2);

	n[1] = 1;
	c[0] = 'a';

	for (size_t i = 0; i < n.size(); i++)
		std::cout << n[i] << std::endl;

	for (size_t i = 0; i < c.size(); i++)
			std::cout << c[i] << std::endl;

	return 0;
} 
