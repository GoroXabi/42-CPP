#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <ctime> 
#include <random> 
#include <sys/ioctl.h>

#define HMAG		"\033[95m"
#define HCYA		"\033[96m"
#define HDCY		"\033[36m"
#define HBLU		"\033[94m"
#define HGRE		"\033[92m"
#define HYEL		"\033[93m"
#define HRED		"\033[91m"
#define TBOL		"\033[1m"
#define TULN		"\033[4m"
#define RST			"\033[0m"


#define nextJacobsthal(n_jacobsthal) ((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3

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

/*-----------------PUBLIC_FUNCTIONS------------------*/

	static void shortList(size_t elements);
	static void shortVector(size_t elements);
	static void shortList(std::list<int> list);
	static void shortVector(std::vector<int> vector);

	static unsigned int comparations;

};

void print_secuence(std::list<int> secuence);
void print_secuence(std::vector<int> secuence);

template <typename T>
typename T::iterator aait(T &list, size_t idx)
{
	if (idx > list.size())
		return(list.end());
	if (idx == 0)
		return(list.begin());

	typename T::iterator it = list.begin();
	for (size_t i = 0; i < idx; i++)
		it++;

	return(it);
}


#endif
