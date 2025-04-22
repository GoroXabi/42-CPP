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


void myInsert(std::vector<std::vector<int> > &vectore, std::vector<std::vector<int> >::iterator iterator, std::vector<int> element, std::vector<int> &idxs)
{
    int idx = std::distance(vectore.begin(), iterator);

    for (std::vector<int>::iterator it = idxs.begin(); it != idxs.end(); it++)
    {
        if (idx <= *it)
            (*it)++;
    }

    vectore.insert(iterator, element);
}
void myErase(std::vector<int> &vectore, std::vector<int>::iterator &iterator, std::vector<int> &idxs)
{
    int idx = std::distance(vectore.begin(), iterator);

    for (std::vector<int>::iterator it = idxs.begin(); it != idxs.end(); it++)
    {
        if (idx < *it)
            (*it)--;
    }

    vectore.erase(iterator);
}


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
			std::cout << (*current_it <= 9 ? "0" : "") << *current_it << " ";
		std::cout << "] ";
		color++;
		color = color > 3 ? 0 : color;
	}
	std::cout << std::endl;
}
void print_secuence(std::vector<std::vector<int> > secuence)
{
	const char *colors[4] = {HRED, HGRE, HMAG, HBLU};
	int color = 0;
	for (std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << colors[color];
		std::cout << "[ ";
		std::vector<int> current = *it;
		for (std::vector<int>::iterator current_it = current.begin(); current_it != current.end(); current_it++)
			std::cout << (*current_it <= 9 ? "0" : "") << *current_it << " ";
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
		std::cout << (*it <= 9 ? "0" : "") << *it << " ";
		std::cout << "] ";
		color++;
		color = color > 3 ? 0 : color;
	}
	std::cout << std::endl;
}
void print_secuence(std::vector<int> secuence)
{
	std::cout << "[ ";
	for (std::vector<int>::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << (*it <= 9 ? "0" : "") << *it << " ";
	}
	std::cout << "] ";
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

		PmergeMe::comparations++;

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
std::vector<std::vector<int> > unite(std::vector<std::vector<int> > secuence)
{
	std::vector<std::vector<int> > new_secuence;
	

	for (std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end() - 1; it++)
	{
		std::vector<int> tmp;

		PmergeMe::comparations++;


		if (it->back() <= (it + 1)->back())
		{
			tmp = *it;
			tmp.insert(tmp.end(), (it + 1)->begin(), (it + 1)->end());
		}
		else
		{
			tmp = *(it + 1);
			tmp.insert(tmp.end(), (it)->begin(), (it)->end());
		}
		new_secuence.push_back(tmp);
		it++;
		if (it + 1 == secuence.end())
			break; 
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
std::vector<int> splitVector(std::vector<int> &to_split)
{
	size_t middle = to_split.size() / 2;
	std::vector<int> new_vector(to_split.begin(), to_split.begin() + middle);
	to_split.erase(to_split.begin(), to_split.begin()+ middle);
	return (new_vector);
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
std::vector<std::vector<int> > divide(std::vector<std::vector<int> > secuence)
{
	std::vector<std::vector<int> > new_secuence;

	for ( std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		new_secuence.push_back(splitVector(*it));
		new_secuence.push_back(*it);
	}

	return(new_secuence);
}

bool is_shortedL(std::list<std::list<int> > secuence)
{
	for(std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::list<std::list<int> >::iterator tmp = it;
		tmp++;
		if (tmp == secuence.end())
			break;
		if (it->back() > (tmp)->back())
		{
			std::cout << it->back() << " is greater than " << (tmp)->back() << std::endl;
			return(false);
		}
	}
	return(true);

}
bool is_shortedV(std::vector<std::vector<int> > secuence)
{
	for(std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::vector<std::vector<int> >::iterator tmp = it;
		tmp++;
		if (tmp == secuence.end())
			break;
		if (it->back() > (tmp)->back())
		{
			std::cout << it->back() << " is greater than " << (tmp)->back() << std::endl;
			return(false);
		}
	}
	return(true);
}

#define nextJacobsthal(n_jacobsthal) ((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3

bool myCompL(const int leftList, const std::list<int> rigthList)
{
	PmergeMe::comparations++;
	return(leftList < rigthList.back());
}
bool myCompV(const int leftVector, const std::vector<int> rigthVector)
{
	PmergeMe::comparations++;
	return(leftVector < rigthVector.back());
}

std::list<std::list<int> > insertePendIntoMain(
	std::list<std::list<int> > &main,
	std::list<std::list<int> > &pend,
	std::list<std::list<std::list<int> >::iterator> &it_list)
{
	int n_jacobsthal = 2;
	size_t jacobsthal;


	if (pend.empty() || it_list.empty())
		return(main);

	if(it_list.empty() && !pend.empty())
	{
		main.insert(std::upper_bound(main.begin(), main.end(), pend.begin()->back(), myCompL), pend.front());
		return (main);
	}

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
			main.insert(std::upper_bound(main.begin(), aN, bN->back(), myCompL), *bN);
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
std::vector<std::vector<int> > insertePendIntoMain(
	std::vector<std::vector<int> > &main,
	std::vector<std::vector<int> > &pend,
	std::vector<int> &idxs)
{
	int n_jacobsthal = 2;
	size_t jacobsthal;


	if (pend.empty() || idxs.empty())
		return(main);

	if(idxs.empty() && !pend.empty())
	{
		main.insert(std::upper_bound(main.begin(), main.end(), pend.begin()->back(), myCompV), pend.front());
		return (main);
	}

	while (!pend.empty())
	{
		jacobsthal = nextJacobsthal(n_jacobsthal + 1) - nextJacobsthal(n_jacobsthal);
		
		if (jacobsthal > idxs.size())
			jacobsthal = idxs.size() - 1;
		if (idxs.size() == 1)
			jacobsthal = 1;

		int tmp_jacobsthal = jacobsthal;
		
		while(tmp_jacobsthal > 0)
		{		
			std::vector<std::vector<int> >::iterator aN = (idxs[tmp_jacobsthal - 1] == -1) ? main.end() : main.begin() + idxs[tmp_jacobsthal - 1];
			std::vector<std::vector<int> >::iterator bN = pend.begin() + (tmp_jacobsthal - 1);
			myInsert(main, std::upper_bound(main.begin(), aN, bN->back(), myCompV), *bN, idxs);
			tmp_jacobsthal--;
		}

		for (size_t i = 0; i < jacobsthal; i++)
		{
			idxs.erase(idxs.begin());
			pend.erase(pend.begin());
		}
		n_jacobsthal++;
	}
	return(main);
}

void insert(std::list<std::list<int> > &secuence)
{
	std::list<std::list<int> > pend;
	std::list<std::list<std::list<int> >::iterator> it_list;
	int noRandomAccess = 3;

	if (secuence.size() <= 3)
		it_list.push_back(secuence.end());
	else
	{
		for (std::list<std::list<int> >::iterator it = aait(secuence, 3); it != secuence.end(); it++)
		{
			if(noRandomAccess % 2)
				it_list.push_back(aait(secuence, noRandomAccess));
			noRandomAccess++;		
		}
		if (secuence.size() % 2)
			it_list.push_back(secuence.end());
	}

    size_t list_size = secuence.size();
    for (size_t i = 2; i < list_size; i++)
	{
        pend.splice(pend.end(), secuence, aait(secuence, i), aait(secuence, i + 1));
	}

	secuence = insertePendIntoMain(secuence, pend, it_list);

}
void insert(std::vector<std::vector<int> > &secuence)
{
	std::vector<std::vector<int> > pend;
	std::vector<int> idxs;
    size_t vector_size = secuence.size();

    for (size_t i = 2; i < vector_size; i += 2)
	{
		pend.push_back(*(secuence.begin() + i));
	}

	for (size_t i = secuence.size() - 1; i >= 2; i--)
	{
		if (!(i % 2))
			secuence.erase(secuence.begin() + i);
	}

	for (std::vector<std::vector<int> >::iterator it = secuence.begin() + 2; it != secuence.end(); it++)
		idxs.push_back(std::distance(secuence.begin(), it));

	if ((secuence.size() - 2) - pend.size() > 1)
	{
		idxs.push_back(-1);
	}

	secuence = insertePendIntoMain(secuence, pend, idxs);
}

std::list<std::list<int> > shortL(std::list<std::list<int> > secuence)
{
	std::list<int> rest;

	if (secuence.size() % 2)
	{
		rest = secuence.back();
		secuence.pop_back();
	}

	secuence = unite(secuence);

 	if (secuence.size() > 1)
		secuence = shortL(secuence);

	secuence = divide(secuence);

	if (rest.size() > 0)
		secuence.push_back(rest);

	insert(secuence);
	return (secuence);
}
std::vector<std::vector<int> > shortV(std::vector<std::vector<int> > secuence)
{
	std::vector<int> rest;

	if (secuence.size() % 2)
	{
		rest = secuence.back();
		secuence.pop_back();
	}

	secuence = unite(secuence);

 	if (secuence.size() > 1)
		secuence = shortV(secuence);

	secuence = divide(secuence);
	
	if (rest.size() > 0)
		secuence.push_back(rest);

	
	insert(secuence);

	return (secuence);
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}
int PmergeMe::comparations = 0;

std::list<std::list<int> > randSecuenceL(size_t elements)
{
	std::list<std::list<int> > randSecuence;
	srand(time(NULL));
	for (size_t i = 0; i < elements; i++)
	{
		std::list<int> init;
		init.push_back(rand() % elements);
		randSecuence.push_back(init);
	}
	return(randSecuence);
}
std::vector<std::vector<int> > randSecuenceV(size_t elements)
{
	std::vector<std::vector<int> > randSecuence;
	srand(time(NULL));
	for (size_t i = 0; i < elements; i++)
	{
		std::vector<int> init;
		init.push_back(rand() % elements);
		randSecuence.push_back(init);
	}
	return(randSecuence);
}
void PmergeMe::shortVector(size_t elements)
{
	std::vector<std::vector<int> > secuence;
	
	double time_used = 0;

	comparations = 0 ;
	std::cout <<  HMAG"VECTOR" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		secuence = randSecuenceV(elements);
		
		clock_t start_time = clock();
		if (elements != 1 && elements != 0)
			secuence = shortV(secuence);
		clock_t end_time = clock();
		time_used += ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		std::cout << ((is_shortedV(secuence) && secuence.size() == elements) ? "✅ " : "❌ ") << std::flush;
	}
	std::cout << std::endl;
	
	comparations /= 100;
	std::cout << HBLU <<  secuence.size() << " elements, " << "worst case : " << F(secuence.size()) << std::endl;
	std::cout << HMAG <<  secuence.size() << " elements, " << "average comparations done : " << comparations << std::endl;
	std::cout << ((F(secuence.size()) >= comparations) ? HGRE"Comparation number in range" : HRED"Comparation number out of range") << std::endl;
	
	std::cout << HMAG << "Total time used: " << time_used << std::endl;
	std::cout << HMAG << "Average time used: " << time_used / 100 << std::endl;

}

void PmergeMe::shortList(size_t elements)
{
	std::list<std::list<int> > secuence;
	
	double time_used = 0;

	comparations = 0 ;
	std::cout <<  HBLU"LIST" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		secuence = randSecuenceL(elements);

		clock_t start_time = clock();
		if (elements != 1 && elements != 0)
			secuence = shortL(secuence);
		clock_t end_time = clock();
		time_used += ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		std::cout << ((is_shortedL(secuence) && secuence.size() == elements) ? "✅ " : "❌ ") << std::flush;

	}
	std::cout << std::endl;
	
	comparations /= 100;
	std::cout << HBLU <<  secuence.size() << " elements, " << "worst case : " << F(secuence.size()) << std::endl;
	std::cout << HMAG <<  secuence.size() << " elements, " << "average comparations done : " << comparations << std::endl;
	std::cout << ((F(secuence.size()) >= comparations) ? HGRE"Comparation number in range" : HRED"Comparation number out of range") << std::endl;
	
	std::cout << HMAG << "Total time used: " << time_used << std::endl;
	std::cout << HMAG << "Average time used: " << time_used / 100 << std::endl;

}