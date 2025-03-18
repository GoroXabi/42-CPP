#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	std::string val(argv[1]);
    ScalarConverter::convert(val);
    return (0);
}
