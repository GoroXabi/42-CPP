	#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <typeinfo>
#include <stdlib.h>
#include <iomanip>
#include <errno.h>

class	ScalarConverter
{
private:

/*--------------------CONSTRUCTORS-------------------*/

	ScalarConverter();
	ScalarConverter(ScalarConverter &model);
	ScalarConverter&operator=(const ScalarConverter&model);

/*--------------------DESTRUCTORS--------------------*/

	~ScalarConverter();

public:

/*-----------------PUBLIC_FUNCTIONS------------------*/

	static void	convert(std::string &literal);

};

#endif
