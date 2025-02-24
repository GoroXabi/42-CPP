#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
private:
	T				*_data;
	unsigned int	_size; 

public:

/*--------------------CONSTRUCTORS-------------------*/
	Array();
	Array(unsigned int n);
	Array(const Array &model);
	Array &operator=(const Array &model);
	T	&operator[](unsigned int idx);

/*--------------------DESTRUCTORS--------------------*/

	~Array();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	unsigned int	size(void) const;
};

#endif
