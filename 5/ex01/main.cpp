#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{
	Bureaucrat		sebas("sebas", 70);
	Form			a32("a32", 60, 15);

	std::cout << HBLU << sebas << RST << std::endl;
	std::cout << HMAG << a32 << RST << std::endl;

	try
	{
		Form	a34("a34", -1, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << HRED << e.what() << RST << std::endl;
	}


	sebas.signForm(a32);
	for (size_t i = 0; i < 30; i++)	
		sebas.promote();
	sebas.signForm(a32);
	return (0);
};
