#include <iostream>
#include "PmergeMe.hpp"
#include <limits>
#include <time.h>
#include <errno.h>

int main(int argc, char **argv) {

    std::list<int> list;
    std::vector<int> vector;

    errno = 0;
    char *err;

    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return(1);
    }
    if ((std::string)argv[1] == "-test")
    {
        if (argc != 3)
        {
            std::cout << HGRE"In the test mode the input whill be the number of elements of the secuence."<< RST << std::endl;
            return(1);
        }
        double tmp = std::strtod(argv[2], &err);
        std::cout << tmp << errno << *err << std::endl;
        if (errno != 0 || *err != 0 || (tmp > std::numeric_limits<int>::max()) || (tmp < 0))
        {
            std::cout << HRED"Not a valid imput for test mode" << RST << std::endl;
            return(1);
        }
        winsize w;
	    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	    std::cout << HGRE << std::setw(w.ws_col/2 + 5) << std::setfill('-') << "TEST MODE:" << std::setw(w.ws_col/2 - 5) << std::setfill('-') << '-' << std::endl << std::endl;
        PmergeMe::shortList((int)tmp);
        PmergeMe::shortVector((int)tmp);
	    std::cout << HGRE << std::setw(w.ws_col) << std::setfill('-') << '-' << RST << std::endl;
        return(0);
    }

    for (int i = 1; i < argc; i++)
    {
        double tmp = std::strtod(argv[i], &err);
        if (errno != 0 || *err != 0 || (tmp > std::numeric_limits<int>::max()) || (tmp < 0))
        {
            std::cout << "Error" << std::endl;
            return(1);
        }
        list.push_back((int)tmp);
        vector.push_back((int)tmp);
    }
    PmergeMe::shortList(list);
    PmergeMe::shortVector(vector);
    return 0;
}
