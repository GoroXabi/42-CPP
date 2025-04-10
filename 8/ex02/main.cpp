#include <iostream>
#include "MutantStack.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"


void main_42()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main(void) {
	MutantStack<> ttmp;
	MutantStack<int> tmp;

	tmp.push(1);
	tmp.push(2);
	tmp.push(3);

	std::cout << HBLU;
	MutantStack<int>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	std::cout << HRED;
	MutantStack<int>::reverse_iterator rit;
	for (rit = tmp.rbegin(); rit != tmp.rend(); ++rit) {
		std::cout << *rit << " ";
	}

	std::cout << std::endl;

	const MutantStack<int> constStack = tmp;

	std::cout << HMAG;
	MutantStack<int>::const_iterator cit;
	for (cit = constStack.begin(); cit != constStack.end(); ++cit) {
		std::cout << *cit << " ";
	}

	std::cout << std::endl;

	const MutantStack<int> rconstStack(tmp);

	std::cout << HGRE;
	MutantStack<int>::const_reverse_iterator rcit;
	for (rcit = rconstStack.rbegin(); rcit != rconstStack.rend(); ++rcit)
		std::cout << *rcit << " ";

	std::cout << std::endl;

	std::cout << RST << "---------" << std::endl;
	main_42();
	return 0;
}