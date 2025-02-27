#include "MutantStack.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &model): std::stack<T, Container>((model)) {}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &model){
	if (this != &model)
		this = MutantStack<T, Container>(model);
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin() {
	return(this->c.begin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end() {
	return(this->c.end());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin() {
	return(this->c.rbegin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend() {
	return(this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin() const {
	return(this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end() const {
	return(this->c.end());
}


template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin() const {
	return(this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend() const {
	return(this->c.rend());
}
