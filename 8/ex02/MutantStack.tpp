#include "MutantStack.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &model): std::stack<T>(static_cast<MutantStack<T>>(model)) {

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &model){
	this =  std::stack<T>(static_cast<MutantStack<T>>(model));
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/
template <typename T>
MutantStack<T>::~MutantStack() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

template <typename T>
MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return(this->c.begin())
}
template <typename T>
MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return(this->c.end())
}

/* 
template <typename T>
T	MutantStack<T>::top(){
	return (std::stack::top());
}

template <typename T>
bool	MutantStack<T>::empty(){
	return (std::stack::empty());
}

template <typename T>
T	MutantStack<T>::push(){
	return (std::stack::top());
}

template <typename T>
T	MutantStack<T>::size(){
	return (std::stack::top());
}
 */