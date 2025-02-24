#include <iostream>
#include "iter.hpp"


int main() {
    int 	array[] = {1, 2, 3, 4, 5};
    char	carray[] = {'a', 'b', 'c', 'd'};

    iter(array, 5, print);
    iter(carray, 4, print);

    return 0;
}
