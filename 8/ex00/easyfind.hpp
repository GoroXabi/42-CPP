#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
bool	easyfind(T container, int n, bool b){
	
	(void)b;
	if (find(container.begin(), container.end(), n) != container.end())
	{
		std::cout << "the element " << n << " is found" << std::endl;
		return(0);
	}
	return(1);
	
}

template <typename T>
bool	easyfind(T container, int n){
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == n)
		{
			std::cout << "the element " << *it << " is found" << std::endl;
			return (0);			
		}
	}
	return(1);
	
}

#endif
