#include "ScalarConverter.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter &model) {

	(void)model;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &model) {

	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

ScalarConverter::~ScalarConverter() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void im_char(char val){
	if (isprint(val))
		std::cout << "char: '" << val << "'" << std::endl;
	else
		std::cout << "char: Non displayeable" << std::endl;
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void im_int(std::string &literal){

	int 	val = std::atoi(literal.c_str());
	double	tmp = std::atof(literal.c_str());
	if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
		std::cout << "ERROR, CANT CAST TO INT WHIOUT OVERFLOW" << std::endl;
	else
	{
		char c = static_cast<char>(val);
		float f = static_cast<float>(val);
		double d = static_cast<double>(val);

		if (val > 128 || val < 0)
			std::cout << "char: impossible" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayeable" << std::endl;
		std::cout << "int: " << val << std::endl;
		if (f != static_cast<int>(f))
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
		if (d != static_cast<int>(d))
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	
	}
}

void im_float(std::string &literal){
	float 	val = std::atof(literal.c_str());
	double	tmp = std::atof(literal.c_str());
	if (tmp > std::numeric_limits<float>::max() || tmp < std::numeric_limits<float>::min())
		std::cout << "ERROR, CANT CAST TO FLOAT WHIOUT OVERFLOW" << std::endl;
	else
	{
		char c = static_cast<char>(val);
		int i = static_cast<int>(val);
		double d = static_cast<double>(val);

		if (val > 128 || val < 0)
			std::cout << "char: impossible" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayeable" << std::endl;
		if (val > (float)std::numeric_limits<int>::max() || val < (float)std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (val != static_cast<int>(val))
			std::cout << "float: " << val << "f" << std::endl;
		else
			std::cout << "float: " << val << ".0f" << std::endl;
		if (d != static_cast<int>(d))
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	}
}

void im_double(std::string &literal){
	if (literal.length() > 308)
		std::cout << "ERROR, CANT CAST TO FLOAT WHIOUT OVERFLOW" << std::endl;
	else
	{
		double 	val = std::atof(literal.c_str());
		char c = static_cast<char>(val);
		double i = static_cast<int>(val);
		float f = static_cast<float>(val);

		if (val > 128 || val < 0)
			std::cout << "char: impossible" << std::endl;
		else if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayeable" << std::endl;
		if (val > (float)std::numeric_limits<int>::max() || val < (float)std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::min())
			std::cout << "float: impossible" << std::endl;
		else if (f != static_cast<int>(f))
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
		if (val != static_cast<int>(val))
			std::cout << "double: " << val << std::endl;
		else
			std::cout << "double: " << val << ".0" << std::endl;
	}
}


void	ScalarConverter::convert(std::string &literal){
	
	int	type = 0;
	int	dot = 0;

	if (literal == "nan")
		type = 4;
	if (literal == "-inf" || literal == "-inff")
		type = 5;
	if (literal == "+inf" || literal == "+inf")
		type = 6;

	for (size_t i = 0; i < literal.length() && type == 0; i++)
	{
		if (literal[0] == '-')
			i++;
		if (literal[i] == '.')
			dot++;
		if ((!isdigit(literal[i])
		&& literal.length() != 1
		&& literal[i] != '.'
		&& !(literal[i] == 'f' && i == literal.length() - 1 && dot == 1))
		|| dot > 1)
		{
			std::cout << "Error" << std::endl;
			return;
		}	
	}

	if (literal.length() != 1 && (literal[literal.length() - 1] == '.' || literal[0] == '.'))
	{
		std::cout << "error" << std::endl;
		return;
	}
	
	if (literal.length() == 1 && !isdigit(literal[0]))
		type = 1;
	if (type == 0 && literal[literal.length() - 1] == 'f' && dot == 1)
		type = 2;
	if (type == 0 && dot == 1)
		type = 3;

	switch (type)
	{
	case 0:
		im_int(literal);
		break;
	case 1:
		im_char(literal[0]);
		break;
	case 2:
		im_float(literal);
		break;
	case 3:
		im_double(literal);
		break;
	case 4:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	case 5:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		break;
	case 6:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		break;
	default:
		break;
	}
}
