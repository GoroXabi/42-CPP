#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack: public std::stack<T>
{
public:

/*--------------------CONSTRUCTORS-------------------*/

	MutantStack(): std::stack<T>() {};
	MutantStack(const MutantStack &model);
	MutantStack &operator=(const MutantStack &model);

/*--------------------DESTRUCTORS--------------------*/

	~MutantStack();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	typedef typename MutantStack<T>::container_type::iterator iterator;
	typedef typename MUtantStack<T>::container_type::const_iterator const_iterator;

	iterator	begin();
	iterator	const_begin();
	iterator	end();
	iterator	const_end();
};

#endif
