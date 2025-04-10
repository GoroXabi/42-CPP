#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <typeinfo>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cmath>

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"


class	PmergeMe
{
private:

/*--------------------CONSTRUCTORS-------------------*/

	PmergeMe();
	PmergeMe(const PmergeMe &model);
	PmergeMe &operator=(const PmergeMe &model);

/*--------------------DESTRUCTORS--------------------*/

	~PmergeMe();

public:

	static void calculateVector(void);
	static void calculateList(void);
	static void calculateDque(void);
/*-----------------PUBLIC_FUNCTIONS------------------*/

};

void print_secuence(std::list<int> secuence);
std::list<int>::iterator aait(std::list<int> &list, size_t idx);


#endif
