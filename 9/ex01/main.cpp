#include <iostream>
#include "RPN.hpp"


int main(int argc, char **argv) {

    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return(1);
    }

	std::string line(argv[1]);
    try
    {
        RPN::calculate(line);
    }
    catch(...)
    {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}
