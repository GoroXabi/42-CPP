#include "Span.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Span::Span() {
	size = 0;
	data.reserve(size);
}

Span::Span(unsigned int N) {
	size = N;
	data.reserve(size);
}

Span::Span(const Span &model) {
	size = model.size;
	data = std::vector<int>(model.data);
}

Span &Span::operator=(const Span &model) {
	size = model.size;
	data = std::vector<int>(model.data);
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Span::~Span() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Span::addNumber(int n){
	if (data.capacity() - data.size() == 0)
		throw std::out_of_range("No te pases mendrugo");
	data.push_back(n);
}

unsigned int	Span::shortestSpan(){
	
	if (data.size() < 2)
		throw std::length_error("No puc");	

	std::vector<int> tmp(data);

	std::sort(tmp.begin(), tmp.end());

	unsigned int max = std::numeric_limits<unsigned int>::max();

	for (std::vector<int>::iterator it = tmp.begin(); it != (tmp.end() - 1); it++)
		if (max > (unsigned int)(*(it + 1) - *it))
			max = (unsigned int)(*(it + 1) - *it);
	return(max);
}

unsigned int	Span::longestSpan(){
	
	if (data.size() < 2)
		throw std::length_error("No puc");	

	std::vector<int> tmp(data);

	std::sort(tmp.begin(), tmp.end());

	return(tmp.back() - tmp.front());

}
