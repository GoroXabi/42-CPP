#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class	ScalarConverter
{
private:

/*--------------------CONSTRUCTORS-------------------*/

	ScalarConverter();
	ScalarConverter(const ScalarConverter &model);
	ScalarConverter &operator=(const ScalarConverter &model);

/*--------------------DESTRUCTORS--------------------*/

	~ScalarConverter();

public:

/*-----------------PUBLIC_FUNCTIONS------------------*/

	static void	convert(std::string &literal);

};

#endif
