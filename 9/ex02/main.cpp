#include <iostream>
#include "PmergeMe.hpp"
#include <time.h>


int main(int argc, char **argv) {

/*     std::list<int> list;
    std::list<int> list2;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    size_t list_size = list.size();
    for (size_t i = 2; i < list_size; i++)
        list2.splice(list2.end(), list, aait(list, i), aait(list, i + 1));

    

    print_secuence(list);
    print_secuence(list2); */

    if (argc < 2)
        PmergeMe::calculateList(10);
    else
        PmergeMe::calculateList((size_t)atoi(argv[1]));

    return 0;

}


