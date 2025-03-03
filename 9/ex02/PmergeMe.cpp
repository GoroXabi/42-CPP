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
			std::cout << (*current_it < 9 ? "0" : "") << *current_it << " ";
		std::cout << "] ";
		color++;
		color = color > 3 ? 0 : color;
	}
	std::cout << std::endl;
}

std::vector<std::vector<int> > calculate(std::vector<std::vector<int> > secuence)
{
	print_secuence(secuence);
	std::vector<std::vector<int> > new_secuence;
	std::vector<std::vector<int> >::iterator it = secuence.begin();
	for (; it != secuence.end();)
	{
		if (secuence.end() - it < 2)
		{
			break;
		}
		else
		{	
			std::vector<int> v1 = *it;
			it++;
			std::vector<int> v2 = *it;
			it++;
			std::vector<int> v3;
			if (v1.back() < v2.back())
			{
				v3.insert(v3.end(), v1.begin(), v1.end());
				v3.insert(v3.end(), v2.begin(), v2.end());
			}
			else
			{
				v3.insert(v3.end(), v2.begin(), v2.end());
				v3.insert(v3.end(), v1.begin(), v1.end());
			}
			new_secuence.push_back(v3);
		}
	}

	std::vector<std::vector<int> > ret;

	if (new_secuence.size() > 1)
		new_secuence = calculate(new_secuence);

	int secuence_size = secuence.front().size();
	int elemet = 0;
	for(std::vector<std::vector<int> >::iterator ret_it = secuence.begin(); ret_it != secuence.end(); ret_it++)
	{
		if (secuence.size() % 2 && secuence.end() - ret_it < 2)
		{
			break;
		}
		//ESTAS MATANDOTE AQUI POR QUE NECESITAS QUE CUANDO LOS PAQUETES VUELVEN
		//DE LA RECURSIVIDAD TENGAN LA ESTRUCTURA QUE TENIAN, MUCHO ANIMO
		int start = elemet * secuence_size;
		std::vector<int> subvector(new_secuence.begin() + start, new_secuence.begin() + start + secuence_size + 1);
		ret.push_back(subvector);
	}

	if (secuence.size() % 2)
		ret.push_back(secuence.back());
		
	return(ret);
	
}

void PmergeMe::calculateVector()
{
	std::vector<std::vector<int> > secuence;
	std::vector<int> init;
	/* 
	size_t count = 104;
	for (size_t i = 0; i < count; i++)
		init.push_back(rand() % 100);
	 */
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
	for (std::vector<int>::iterator it = init.begin(); it != init.end();)
	{
		std::vector<int> pair;
		if (init.end() - it > 1)
		{
			int n1 = *it;
			it++;
			int n2 = *it;
			it++;
			if (n1 < n2)
			{
				pair.push_back(n1);
				pair.push_back(n2);
			}
			else
			{
				pair.push_back(n2);
				pair.push_back(n1);
			}
		}
		else
		{
			pair.push_back(*it);
			it++;
		}
		secuence.push_back(pair);
	}
	secuence = calculate(secuence);
	print_secuence(secuence);
}