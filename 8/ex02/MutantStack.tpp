#include "MutantStack.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &model): std::stack<T>((model)) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &model){
	if (this != &model)
		this = MutantStack<T>(model);
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

template <typename T>
MutantStack<T>::~MutantStack() {}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return(this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return(this->c.end());
}
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() {
	return(this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend() {
	return(this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return(this->c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const {
	return(this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const {
	return(this->c.rend());
}
