#include <iostream>
#include "PmergeMe.hpp"
#include <time.h>

int main(int argc, char **argv) {
 
    if (argc < 2)
    {
        PmergeMe::shortList(10);
        PmergeMe::shortVector(10);
    }
    else
    {
        PmergeMe::shortList((size_t)atoi(argv[1]));
        PmergeMe::shortVector((size_t)atoi(argv[1]));
    }

    return 0;

}


/* 
    std::list<int> lista;

    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);
    lista.push_back(5);
    lista.push_back(6);

    print_secuence(lista);

    std::list<std::list<int>::iterator > it_list;

    for (std::list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        if (!(*it % 2))
            it_list.push_back(it);
    }
    
    std::cout << **it_list.begin() << " ... " << *it_list.back() << std::endl;


    for (std::list<int>::iterator it = lista.begin(); it != lista.end();)
    {
        std::list<int>::iterator tmp = it++;
        if ((*tmp % 2))
        {
            lista.erase(tmp);
        }
    }

    print_secuence(lista);


    for (std::list<std::list<int>::iterator>::iterator it = it_list.begin(); it != it_list.end(); it++)
        std::cout << HRED << **it << std::endl;

    lista.push_front(5);
    lista.push_front(3);
    lista.push_front(1);
    
    print_secuence(lista);


    for (std::list<std::list<int>::iterator>::iterator it = it_list.begin(); it != it_list.end(); it++)
        std::cout << HRED << **it << std::endl;

    std::cout << "..." <<  std::endl;

    std::vector<int> vectore;

    vectore.push_back(1);
    vectore.push_back(2);
    vectore.push_back(3);
    vectore.push_back(4);
    vectore.push_back(5);
    vectore.push_back(6);

    print_secuence(vectore);

    std::vector<std::vector<int>::iterator> it_vectore;

    for (std::vector<int>::iterator it = vectore.begin(); it != vectore.end(); it++)
    {
        if (!(*it % 2))
            it_vectore.push_back(it);
    }

    std::cout << **it_vectore.begin() << " ... " << *it_vectore.back() << std::endl;


    for (std::vector<int>::iterator it = vectore.begin(); it != vectore.end();)
    {
        std::vector<int>::iterator tmp = it++;
        if ((*tmp % 2))
        {
            vectore.erase(tmp);
        }
    }

    print_secuence(vectore);
    for (std::vector<std::vector<int>::iterator>::iterator it = it_vectore.begin(); it != it_vectore.end(); it++)
        std::cout << HRED << **it << std::endl;

    vectore.push_back(1);
    vectore.push_back(3);
    vectore.push_back(5);

    print_secuence(vectore);
    
    for (std::vector<std::vector<int>::iterator>::iterator it = it_vectore.begin(); it != it_vectore.end(); it++)
        std::cout << HRED << **it << std::endl;


    (void)argc;
    (void)argv;
 */
