#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{
    Bureaucrat jose("jose", 99);

    std::cout << jose << std::endl;

    Bureaucrat paco("paco", 20);
    Bureaucrat tulio;
    try
    {
        paco = Bureaucrat("paco", 500);
        Bureaucrat jaime("paco", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << paco << std::endl;
    std::cout << tulio << std::endl;


    return (0);
};
