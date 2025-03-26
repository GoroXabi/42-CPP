#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

#define MAX_VAL 750
int main_42()
{

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main() {
	
	Array<int> 	n(5);
	Array<char> c(5);
	Array<std::string> s(3);

	n[2] = 1;
	
	c[0] = 'H';
	c[1] = 'e';
	c[2] = 'l';
	c[3] = 'l';
	c[4] = 'o';

	s[0] = "first";
	s[1] = "second";
	s[2] = "third";

	try
	{
		s[3] = "fourth";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		s[-1] = "zero";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << HMAG;
	std::cout << *c << std::endl;
	std::cout << *n << std::endl;
	std::cout << *s << std::endl;

	std::cout << HBLU;
	for (size_t i = 0; i < n.size(); i++)
		std::cout << n[i] << std::endl;

	std::cout << HRED;
	for (size_t i = 0; i < c.size(); i++)
			std::cout << c[i] << std::endl;
	
	std::cout << HGRE;
	for (size_t i = 0; i < s.size(); i++)
			std::cout << s[i] << std::endl;

	std::cout << RST;
	main_42();
	return 0;
}
