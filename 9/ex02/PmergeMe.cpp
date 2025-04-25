#include "PmergeMe.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &model) {(void)model;}

PmergeMe &PmergeMe::operator=(const PmergeMe &model) {
	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

PmergeMe::~PmergeMe() {}


/*--------------------------------------------------------------*/
/*							   OTHER							*/
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

/*--------------------------------------------------------------*/
/*							UPPERBOUND							*/
/*--------------------------------------------------------------*/

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

/*--------------------------------------------------------------*/
/*							  INSERT							*/
/*--------------------------------------------------------------*/

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

/*--------------------------------------------------------------*/
/*							   MERGE							*/
/*--------------------------------------------------------------*/

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

/*--------------------------------------------------------------*/
/*						  RECURSIVE_LOOP						*/
/*--------------------------------------------------------------*/

std::list<std::list<int> > mergeInsertShort(std::list<std::list<int> > secuence)
{
	std::list<int> rest;

	if (secuence.size() % 2)
	{
		rest = secuence.back();
		secuence.pop_back();
	}

	secuence = unite(secuence);

 	if (secuence.size() > 1)
		secuence = mergeInsertShort(secuence);

	secuence = divide(secuence);

	if (rest.size() > 0)
		secuence.push_back(rest);

	insert(secuence);

	return (secuence);
}
std::vector<std::vector<int> > mergeInsertShort(std::vector<std::vector<int> > secuence)
{
	std::vector<int> rest;

	if (secuence.size() % 2)
	{
		rest = secuence.back();
		secuence.pop_back();
	}

	secuence = unite(secuence);

 	if (secuence.size() > 1)
		secuence = mergeInsertShort(secuence);

	secuence = divide(secuence);
	
	if (rest.size() > 0)
		secuence.push_back(rest);

	
	insert(secuence);

	return (secuence);
}

/*--------------------------------------------------------------*/
/*							UTIL_FUNCS							*/
/*--------------------------------------------------------------*/

void print_secuence(std::list<std::list<int> > secuence)
{
	for (std::list<std::list<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::list<int> current = *it;
		for (std::list<int>::iterator current_it = current.begin(); current_it != current.end(); current_it++)
			std::cout << *current_it << " ";
	}
	std::cout << std::endl;
}
void print_secuence(std::vector<std::vector<int> > secuence)
{
	for (std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::vector<int> current = *it;
		for (std::vector<int>::iterator current_it = current.begin(); current_it != current.end(); current_it++)
			std::cout << *current_it << " ";
	}
	std::cout << std::endl;
}
void print_secuence(std::list<int> secuence)
{
	for (std::list<int>::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void print_secuence(std::vector<int> secuence)
{
	for (std::vector<int>::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
		{
			std::cout << it->back() << " is greater than " << (tmp)->back() << std::endl;
			return(false);
		}
	}
	return(true);

}
bool is_shorted(std::vector<std::vector<int> > secuence)
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


unsigned int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}
unsigned int PmergeMe::comparations = 0;

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
		init.push_back(rand());
		randSecuence.push_back(init);
	}
	return(randSecuence);
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void PmergeMe::shortVector(size_t elements)
{
	std::vector<std::vector<int> > secuence;
	
	unsigned int wortsCaseC = 0;
	unsigned int bestCaseC = -1;
	double wortsCaseT = 0;
	double bestCaseT = std::numeric_limits<double>::max();
	unsigned int totalComparations = 0;
	double time_used = 0;

	winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	std::cout << TBOL HMAG << std::setw(w.ws_col/2 + 3) << std::setfill('-') << "VECTOR" << std::setw(w.ws_col/2 - 3) << std::setfill('-') << '-' << RST << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		comparations = 0 ;
		secuence = randSecuenceV(elements);
		
		clock_t start_time = clock();
		if (elements != 1 && elements != 0)
			secuence = mergeInsertShort(secuence);
		clock_t end_time = clock();
		std::cout << ((is_shorted(secuence) && secuence.size() == elements) ? "✅ " : "❌ ") << std::flush;

		totalComparations += comparations;
		if (comparations < bestCaseC)
			bestCaseC = comparations;
		if (comparations > wortsCaseC)
			wortsCaseC = comparations;
		time_used += ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		if ((((double) (end_time - start_time))  / CLOCKS_PER_SEC) < bestCaseT)
			bestCaseT = ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		if ((((double) (end_time - start_time))  / CLOCKS_PER_SEC) > wortsCaseT)
			wortsCaseT = ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		usleep(10000);
	}
	std::cout << std::endl << std::endl;
	
	totalComparations /= 100;
	
	std::cout << HYEL << "Elements:\t\t" << TBOL TULN << secuence.size() << RST << std::endl;

	std::cout << HYEL"Worst case posible :\t"<< TBOL TULN << F(secuence.size()) << RST HYEL << " comparations" << std::endl;
	std::cout << HBLU"Worst in all tests :\t" << ((F(secuence.size()) >= wortsCaseC) ? HGRE:HRED) << wortsCaseC << " comparations" << std::endl;
	std::cout << HBLU"Best in all test :\t" << ((F(secuence.size()) >= bestCaseC) ? HGRE:HRED) << bestCaseC << " comparations" << std::endl;
	std::cout << HBLU"Average of all test:\t" << ((F(secuence.size()) >= totalComparations) ? HGRE:HRED) << totalComparations << " comparations" << std::endl;
	std::cout << HMAG << "Total time used:\t" << HCYA << time_used << " seconds" << std::endl;
	std::cout << HMAG << "Best time:\t\t" << HCYA << bestCaseT * 1000000 << " nano seconds" << std::endl;
	std::cout << HMAG << "Worst time:\t\t" << HCYA << wortsCaseT * 1000000 << " nano seconds" << std::endl;
	std::cout << HMAG << "Average time used:\t" << HCYA << int((time_used / 100) * 1000000) << " nano seconds" << RST << std::endl;

	std::cout << TBOL HMAG << std::setw(w.ws_col) << std::setfill('-') << '-' << RST << std::endl << std::endl;
}
void PmergeMe::shortList(size_t elements)
{
	std::list<std::list<int> > secuence;
	
	unsigned int wortsCaseC = 0;
	unsigned int bestCaseC = -1;
	double wortsCaseT = 0;
	double bestCaseT = std::numeric_limits<double>::max();
	unsigned int totalComparations = 0;
	double time_used = 0;

	winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	std::cout << TBOL HBLU << std::setw(w.ws_col/2 + 2) << std::setfill('-') << "LIST" << std::setw(w.ws_col/2 - 2) << std::setfill('-') << '-' << RST << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		comparations = 0 ;
		secuence = randSecuenceL(elements);
		
		clock_t start_time = clock();
		if (elements != 1 && elements != 0)
			secuence = mergeInsertShort(secuence);
		clock_t end_time = clock();
		std::cout << ((is_shorted(secuence) && secuence.size() == elements) ? "✅ " : "❌ ") << std::flush;

		totalComparations += comparations;
		if (comparations < bestCaseC)
			bestCaseC = comparations;
		if (comparations > wortsCaseC)
			wortsCaseC = comparations;
		time_used += ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		if ((((double) (end_time - start_time))  / CLOCKS_PER_SEC) < bestCaseT)
			bestCaseT = ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		if ((((double) (end_time - start_time))  / CLOCKS_PER_SEC) > wortsCaseT)
			wortsCaseT = ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
		usleep(10000);
	}
	std::cout << std::endl << std::endl;
	
	totalComparations /= 100;
	
	std::cout << HYEL << "Elements:\t\t" << TBOL TULN << secuence.size() << RST << std::endl;

	std::cout << HYEL"Worst case posible :\t"<< TBOL TULN << F(secuence.size()) << RST HYEL << " comparations" << std::endl;
	std::cout << HBLU"Worst in all tests :\t" << ((F(secuence.size()) >= wortsCaseC) ? HGRE:HRED) << wortsCaseC << " comparations" << std::endl;
	std::cout << HBLU"Best in all test :\t" << ((F(secuence.size()) >= bestCaseC) ? HGRE:HRED) << bestCaseC << " comparations" << std::endl;
	std::cout << HBLU"Average of all test:\t" << ((F(secuence.size()) >= totalComparations) ? HGRE:HRED) << totalComparations << " comparations" << std::endl;
	
	std::cout << HMAG << "Total time used:\t" << HCYA << time_used << " seconds" << std::endl;
	std::cout << HMAG << "Best time:\t\t" << HCYA << bestCaseT * 1000000 << " nano seconds" << std::endl;
	std::cout << HMAG << "Worst time:\t\t" << HCYA << wortsCaseT * 1000000 << " nano seconds" << std::endl;
	std::cout << HMAG << "Average time used:\t" << HCYA << int((time_used / 100) * 1000000) << " nano seconds" << RST << std::endl;

	std::cout << TBOL HBLU << std::setw(w.ws_col) << std::setfill('-') << '-' << RST << std::endl << std::endl;

}

void PmergeMe::shortList(std::list<int> list)
{
	std::list<std::list<int> > secuence;
	std::cout << "Before:\t";
	print_secuence(list);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::list<int> tmp;
		tmp.push_back(*it);
		secuence.push_back(tmp);
	}
	clock_t start_time = clock();
	if (list.size() != 1 && list.size() != 0)
		secuence = mergeInsertShort(secuence);
	clock_t end_time = clock();
	double totalTime =  ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
	std::cout << "After:\t";
	print_secuence(secuence);
	std::cout << "Time to process a range of " << secuence.size() << \
	" elements with std::list : " << totalTime * 1000000 << " us" << std::endl;
}
void PmergeMe::shortVector(std::vector<int> vector)
{
	std::vector<std::vector<int> > secuence;

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::vector<int> tmp;
		tmp.push_back(*it);
		secuence.push_back(tmp);
	}
	clock_t start_time = clock();
	if (vector.size() != 1 && vector.size() != 0)
		secuence = mergeInsertShort(secuence);
	clock_t end_time = clock();
	double totalTime =  ((double) (end_time - start_time))  / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << secuence.size() << \
	" elements with std::vector : " << totalTime * 1000000 << " us" << std::endl;

	(void)vector;
}
