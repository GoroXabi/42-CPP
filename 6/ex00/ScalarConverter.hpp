	#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <typeinfo>
#include <stdlib.h>
#include <iomanip>

class	ScalarConverter
{
private:

/*--------------------CONSTRUCTORS-------------------*/

	ScalarConverter();

/*--------------------DESTRUCTORS--------------------*/

	~ScalarConverter();

public:

/*-----------------PUBLIC_FUNCTIONS------------------*/

	static void	convert(std::string &literal);

};

#endif
