#include <iostream>
#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {

    if (argc != 2)
        return(1);

    std::string input(argv[1]);
    BitcoinExchange b;
    b.calculate(input);
    return 0;
}
