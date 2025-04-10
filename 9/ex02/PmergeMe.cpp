#include "PmergeMe.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &model) {
	(void)model;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &model) {
	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

PmergeMe::~PmergeMe() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void print_secuence(std::list<std::list<int> > secuence)
{
	const char *colors[4] = {HRED, HGRE, HMAG, HBLU};
	int color = 0;
	for (std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << colors[color];
		std::cout << "[ ";
		std::list<int> current = *it;
		for (std::list<int>::iterator current_it = current.begin(); current_it != current.end(); current_it++)
			std::cout << (*current_it < 9 ? "0" : "") << *current_it << " ";
		std::cout << "] ";
		color++;
		color = color > 3 ? 0 : color;
	}
	std::cout << std::endl;
}
void print_secuence(std::list<int> secuence)
{
	const char *colors[4] = {HRED, HGRE, HMAG, HBLU};
	int color = 0;
	for (std::list<int>::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << colors[color];
		std::cout << "[ ";
		std::cout << (*it < 9 ? "0" : "") << *it << " ";
		std::cout << "] ";
		color++;
		color = color > 3 ? 0 : color;
	}
	std::cout << std::endl;
}

std::list<std::list<int> > unite(std::list<std::list<int> > secuence)
{
	std::list<std::list<int> > new_secuence;
	

	for (std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::list<int> tmp;
		std::list<std::list<int> >::iterator first_it = it++;
		std::list<std::list<int> >::iterator second_it = it;

		if (first_it->back() <= second_it->back())
		{
			tmp = *first_it;
			tmp.splice(tmp.end(), *second_it, second_it->begin(), second_it->end());
		}
		else
		{
			tmp = *second_it;
			tmp.splice(tmp.end(), *second_it, first_it->begin(), first_it->end());
		}
		new_secuence.push_back(tmp);
	}

	return(new_secuence);
}

std::list<int>::iterator aait(std::list<int> &list, size_t idx)
{
	if (idx > list.size())
		return(list.end());
	if (idx == 0)
		return(list.begin());
	
	std::list<int>::iterator it = list.begin();
	for (size_t i = 0; i < idx; i++)
		it++;

	return(it);
}
std::list<std::list<int> >::iterator aait(std::list<std::list<int> > &list, size_t idx)
{
	if (idx > list.size())
		return(list.end());
	if (idx == 0)
		return(list.begin());
	
	std::list<std::list<int> >::iterator it = list.begin();
	for (size_t i = 0; i < idx; i++)
		it++;

	return(it);
}

std::list<int> splitList(std::list<int> &to_split)
{
	std::list<int> new_list;
	size_t middle = to_split.size() / 2;

	new_list.splice(new_list.begin(), to_split, to_split.begin(), aait(to_split, middle));
	return (new_list);
}

std::list<std::list<int> > divide(std::list<std::list<int> > secuence)
{
	std::list<std::list<int> > new_secuence;

	for ( std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		new_secuence.push_back(splitList(*it));
		new_secuence.push_back(*it);
	}

	return(new_secuence);
}

bool is_shorted(std::vector<std::vector<int> > secuence)
{
	for(std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end() - 1; it++)
		if (it->back() > (it + 1)->back())
			return(false);
	return(true);

}

int nextJacobsthal(int n_jacobsthal)
{
	return(((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3);
}

std::list<std::list<int> > insertePendIntoMain(std::list<std::list<int> > main, std::list<std::list<int> > pend)
{
	int n_jacobsthal = 2;
	int jacobsthal;

	jacobsthal = nextJacobsthal(n_jacobsthal + 1) - nextJacobsthal(n_jacobsthal);
	jacobsthal++;

	while (pend.size() > 0)
	{
		std::list<std::list<int> >::iterator to_sort = aait(pend, jacobsthal);
	}
	
}

void insert(std::list<std::list<int> > secuence)
{
	std::list<std::list<int> > pend;
	std::list<std::list<std::list<int> >::iterator> it_list;
	int noRandomAccess = 0;

	for (std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		if(noRandomAccess % 2)
			it_list.push_back(it);
		noRandomAccess++;		
	}

    size_t list_size = secuence.size();
    for (size_t i = 2; i < list_size; i++)
	{
        pend.splice(pend.end(), secuence, aait(secuence, i), aait(secuence, i + 1));
	}
	
	std::cout << "pend: ";
	print_secuence(pend);
	std::cout << "main: ";
	print_secuence(secuence);



}

std::list<std::list<int> > calculate(std::list<std::list<int> > secuence)
{
	std::list<int> rest;

	if (secuence.size() % 2)
	{
		rest = secuence.back();
		secuence.pop_back();
	}

	print_secuence(secuence);

	secuence = unite(secuence);

 	if (secuence.size() > 1)
		secuence = calculate(secuence);

	secuence = divide(secuence);

	if (rest.size() > 0)
		secuence.push_back(rest);

	insert(secuence);
	//print_secuence(secuence);
	return (secuence);
}

void PmergeMe::calculateList()
{
	std::list<std::list<int> > secuence;
	std::list<int> init;
 
/* 	size_t count = 40;
	for (size_t i = 0; i < count; i++)
	{
		std::list<int> init;
		init.push_back(rand() % 100);
		secuence.push_back(init);
	} */

	//11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
	init.push_back(11);
	init.push_back(2);
	init.push_back(17);
	init.push_back(0);
	init.push_back(16);
	init.push_back(8);
	init.push_back(6);
	init.push_back(15);
	init.push_back(10);
	init.push_back(3);
	init.push_back(21);
	init.push_back(1);
	init.push_back(18);
	init.push_back(9);
	init.push_back(14);
	init.push_back(19);
	init.push_back(12);
	init.push_back(5);
	init.push_back(4);
	init.push_back(20);
	init.push_back(13);
	init.push_back(7);

	for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
	{
		std::list<int>v;
		v.push_back(*it);
		secuence.push_back(v);
	}
	secuence = calculate(secuence);
	//print_secuence(secuence);
}