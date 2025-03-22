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

std::vector<std::vector<int> > unite(std::vector<std::vector<int> > secuence)
{

	std::vector<std::vector<int> > ret;
	for (std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end();)
	{
		if (secuence.end() - it < 2)
			break;	
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
			ret.push_back(v3);
		}
	}
	return(ret);
}

std::vector<std::vector<int> > divide(std::vector<std::vector<int> > secuence)
{

	std::vector<std::vector<int> > ret;
	size_t middle = secuence.front().size() / 2;
	for (std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end(); it++)
	{
		if (it->size() <= middle || (secuence.size() % 2 && it == secuence.end() - 1 && secuence.size() < 1))
		{
			ret.push_back(*it);
			continue;
		}
		ret.push_back(std::vector<int>(it->begin(), it->begin() + middle));
		ret.push_back(std::vector<int>(it->begin() + middle, it->end()));
	}
	return(ret);
}

bool is_shorted(std::vector<std::vector<int> > secuence)
{
	for(std::vector<std::vector<int> >::iterator it = secuence.begin(); it != secuence.end() - 1; it++)
		if (it->back() > (it + 1)->back())
			return(false);
	return(true);

}

std::vector<std::vector<int> > calculate(std::vector<std::vector<int> > secuence)
{
	std::vector<std::vector<int> > new_secuence(unite(secuence));
	print_secuence(secuence);
	std::cout << "+" << std::endl;
	print_secuence(new_secuence);

	if (new_secuence.size() > 1)
	{
		std::cout << "v" << std::endl;
		new_secuence = calculate(new_secuence);
	}

	std::vector<std::vector<int> > main(divide(new_secuence));
	std::cout << "-" << std::endl;
	print_secuence(main);
	//std::cout << ((is_shorted(ret)) ? "true" : "flase") << std::endl;
	//size_t size = ret.front().size();
	
	std::vector<std::vector<int> >pend;
	for(std::vector<std::vector<int> >::iterator it = main.begin() + 1; main.size() > 2 && it != main.end(); it++)
	{
			//std::cout << ":" << ((it - ret.begin()) + 1) << ":" << it->back() << std::endl;
		if (((it - main.begin()) + 1) % 2)
			pend.push_back(*it);
	}

//	for(std::vector<std::vector<int> >::iterator it = pend.begin(); it != pend.end(); it++)
//		ret.erase(std::find(ret.begin(),ret.end(), *it));

	size_t last_jacob = 1;
	size_t current_jacob = 3;
	size_t pos_jacob = current_jacob - last_jacob;
	std::cout << " ********* " << std::endl;
	print_secuence(pend);
	std::cout << " ********* " << std::endl;
	for(; !pend.empty();)
	{
		std::vector<std::vector<int> >::iterator pend_it
		= (pend.size() > pos_jacob) ? pend.begin() + pos_jacob - 1 : pend.end() - 1;
		std::cout << pend_it->back() << std::endl;
		//pend_it = (pend_it == pend.end()) ? pend.begin() : pend_it;
		for(;pend_it >= pend.begin(); pend_it--)
		{
			/////////////////^^^^^^^^^^^////////////////////
			std::cout << "to pend : " << pend_it->back() << std::endl;
			std::vector<std::vector<int> >::iterator main_it = std::find(main.begin(),main.end(), *pend_it);
			std::cout << "before: " <<  main_it->back() << std::endl;
			print_secuence(main);
			main.erase(main_it);
			std::cout << "after: " <<  main_it->back() << std::endl;
			print_secuence(main);
			for(std::vector<std::vector<int> >::iterator c_it = main.begin(); c_it != main.end(); c_it++)
			{
				if (c_it->back() > pend_it->back())	
				{
					main.insert(c_it, *pend_it);
					break;
				}
				else if (c_it + 1 == main_it)
				{
					main.insert(c_it + 1, *pend_it);
					break;
				}
			}
				std::cout << "after insertion: " << std::endl;
				print_secuence(main);
		}
		print_secuence(pend);
		std::cout << " ********* " << std::endl;
		std::cout << "erase v" << std::endl;
		std::cout << " ********* " << std::endl;
		pend.erase(pend.begin(),
		(pend.size() > pos_jacob) ? pend.begin() + pos_jacob : pend.end());
		print_secuence(pend);
		std::cout << " ********* " << std::endl;
		std::cout << "main " << std::endl;
		print_secuence(main);
		std::cout << " ********* " << std::endl;

		size_t tmp_jacob = (last_jacob * 2) + current_jacob;
		last_jacob = current_jacob;
		current_jacob = tmp_jacob;
		pos_jacob = current_jacob - last_jacob;
		std::cout << "jacob : " << pos_jacob << std::endl;
	}
	std::cout << " ----------- " << std::endl;
	print_secuence(pend);
	std::cout << " ----------- " << std::endl;
	
/* 	for(std::vector<std::vector<int> >::iterator it = ret.begin(); !is_shorted(ret); it++)
	{
		if (it == ret.end())
		{
			ret.push_back(pend.back());
			it == ret.begin();
		}
		int pend_compare = pend.back().back();
		int ret_compare = it->back();
		if ()
		
	}
 */
	if (secuence.size() % 2)
	{
		for(std::vector<std::vector<int> >::iterator c_it = main.begin(); c_it != main.end(); c_it++)
		{				
			if (c_it->back() > secuence.back().back())	
				{
					main.insert(c_it, secuence.back());
					break;
				}
				else if (c_it == secuence.end() - 1)
				{
					main.push_back(secuence.back());
					break;
				}
		}
	}
	
	print_secuence(main);
	std::cout << "^" << std::endl;
	
	return(main);
}

void PmergeMe::calculateVector()
{
	std::vector<std::vector<int> > secuence;
	//std::vector<int> init;
 
	size_t count = 40;
	for (size_t i = 0; i < count; i++)
	{
		std::vector<int> init;
		init.push_back(rand() % 100);
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
	init.push_back(7);
	for (std::vector<int>::iterator it = init.begin(); it != init.end(); it++)
	{
		std::vector<int>v;
		v.push_back(*it);
		secuence.push_back(v);
	}*/
	secuence = calculate(secuence);
	print_secuence(secuence);
}