#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class	Span
{
private:
	std::vector<int>	data;
	unsigned int		size;
	Span();
public:

/*--------------------CONSTRUCTORS-------------------*/

	Span(unsigned int N);
	Span(const Span &model);
	Span &operator=(const Span &model);

/*--------------------DESTRUCTORS--------------------*/

	~Span();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void				addNumber(int n);
	unsigned int		shortestSpan();
	unsigned int		longestSpan();

};

#endif
