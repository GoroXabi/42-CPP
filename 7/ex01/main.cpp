#include "iter.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main() {

    int 	    iarray[] = {1, 2, 3, 4, 5};
    char	    carray[] = {'a', 'b', 'c', 'd'};
    std::string sarray[] = {"first", "second", "third"};

    std::cout << HBLU;
    iter(iarray, 5, print);
    std::cout << HRED;
    iter(carray, 4, print);
    std::cout << HGRE;
    iter(sarray, 3, print);
    std::cout << RST;

    return 0;
}
