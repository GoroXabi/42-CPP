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

bool is_shorted(std::list<std::list<int> > secuence)
{
	for(std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::list<std::list<int> >::iterator tmp = it;
		tmp++;
		if (tmp == secuence.end())
			break;
		if (it->back() > (tmp)->back())
			return(false);
	}
	return(true);

}

#define nextJacobsthal(n_jacobsthal) ((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3

std::list<std::list<int> > insertePendIntoMain(
	std::list<std::list<int> > &main,
	std::list<std::list<int> > &pend,
	std::list<std::list<std::list<int> >::iterator> &it_list)
{
	int n_jacobsthal = 2;
	size_t jacobsthal;


	while (!pend.empty())
	{
		jacobsthal = nextJacobsthal(n_jacobsthal + 1) - nextJacobsthal(n_jacobsthal);
		
		if (jacobsthal > it_list.size())
			jacobsthal = it_list.size() - 1;
		if (it_list.size() == 1)
			jacobsthal = 1;

		int tmp_jacobsthal = jacobsthal;
 		while(tmp_jacobsthal > 0)
		{		
			std::list<std::list<int> >::iterator bN = aait(pend, tmp_jacobsthal - 1);
			std::list<std::list<int> >::iterator aN = *aait(it_list, tmp_jacobsthal - 1);

			for (; aN != main.begin();)
			{
				if (aN->back() < bN->back())
				{
					aN++;
					main.insert(aN, *bN);
					break;
				}
				--aN;
				if (aN == main.begin())
				{
					if (aN->back() < bN->back())
					{
						aN++;
						main.insert(aN, *bN);
					}
					else
						main.push_front(*bN);
					break;
				}
			}
			tmp_jacobsthal--;
		}

		for (size_t i = 0; i < jacobsthal; i++)
		{
			it_list.pop_front();
			pend.pop_front();
		}
		n_jacobsthal++;
	}
	return(main);
	
}

void prueba(std::list<std::list<std::list<int> >::iterator> it_list, size_t n)
{
	std::cout << it_list.size() << std::endl;
	std::list<std::list<std::list<int> >::iterator>::iterator it;
	if (it_list.size() == 0 || n == 0)
		return;
	if (n > it_list.size())
		it = aait(it_list, it_list.size() - 1);
	else
		it = aait(it_list, n - 1);
	for (; it != it_list.begin(); --it)
	{
		std::list<std::list<int> >::iterator tmp = *it;
		std::cout << tmp->back() << " ";
	}
	std::list<std::list<int> >::iterator tmp = *it;
	std::cout << tmp->back() << " ";
	std::cout << std::endl;
	
}

void printaN(std::list<std::list<int> > secuence, std::list<std::list<std::list<int> >::iterator> it_list)
{
	print_secuence(secuence);

	if (it_list.size() > 0)
	{
		std::cout << "last digit of all aN: ";
		for (std::list<std::list<std::list<int> >::iterator>::iterator it = it_list.begin(); it != it_list.end(); it++)
		{
			std::list<std::list<int> >::iterator tmp = *it;
			std::cout << tmp->back() << " ";

		}	
		std::cout << std::endl; 
	}
	else
		std::cout << "no ";


}
void insert(std::list<std::list<int> > &secuence)
{
	std::list<std::list<int> > pend;
	std::list<std::list<std::list<int> >::iterator> it_list;
	int noRandomAccess = 3;

	for (std::list<std::list<int> >::iterator it = aait(secuence, 3); it != secuence.end(); it++)
	{
		if(noRandomAccess % 2)
			it_list.push_back(aait(secuence, noRandomAccess));
		noRandomAccess++;		
	}
	if (secuence.size() % 2)
	{
		it_list.push_back(it_list.back());
	}

	std::cout << "--------------------" << std::endl;
	std::cout << "before: ";
	print_secuence(secuence);


    size_t list_size = secuence.size();
    for (size_t i = 2; i < list_size; i++)
	{
        pend.splice(pend.end(), secuence, aait(secuence, i), aait(secuence, i + 1));
	}

	std::cout << "pend: ";
	print_secuence(pend);
	std::cout << "main: ";
	print_secuence(secuence);
	secuence = insertePendIntoMain(secuence, pend, it_list);
	std::cout << "after insert: ";
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
	//std::list<int> init;
 
	srand(time(NULL));
	for (size_t i = 0; i < 10000; i++)
	{
		std::list<int> init;
		init.push_back(rand() % 10000);
		secuence.push_back(init);
	}

	//11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
/* 	init.push_back(11);
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
	init.push_back(7); */
/* 
	for (std::list<int>::iterator it = init.begin(); it != init.end(); it++)
	{
		std::list<int>v;
		v.push_back(*it);
		secuence.push_back(v);
	} */
	secuence = calculate(secuence);
	std::cout << (is_shorted(secuence) ? "IS SHORTED" : "FUCK") << std::endl;
	//print_secuence(secuence);
}