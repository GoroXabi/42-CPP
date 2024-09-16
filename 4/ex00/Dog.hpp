#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class	Dog: public Animal
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	Dog();
	Dog(const Dog &model);
	Dog &operator=(const Dog &model);

/*--------------------DESTRUCTORS--------------------*/

	~Dog();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void	makeSound() const;

};

#endif
