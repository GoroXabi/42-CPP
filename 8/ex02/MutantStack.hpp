#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T = int, typename Container = std::deque<T> >
class	MutantStack: public std::stack<T, Container>
{
public:

/*--------------------CONSTRUCTORS-------------------*/

	MutantStack();
	MutantStack(const MutantStack &model);
	MutantStack &operator=(const MutantStack &model);

/*--------------------DESTRUCTORS--------------------*/

	~MutantStack();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	typedef typename MutantStack<T>::container_type::iterator iterator;
	typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;

	typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin();
	iterator				end();

	reverse_iterator		rbegin();
	reverse_iterator		rend();
	
	const_iterator			begin() const;
	const_iterator			end() const;
	
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif
