#include <iostream>
#include "Span.hpp"


int main() {

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << "-------------------" << std::endl;
	
	srand (time(NULL));

	Span sp2 = Span(10000);
	
	for (size_t i = 0; i < 10000; i++)
		sp2.addNumber(rand());
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}
