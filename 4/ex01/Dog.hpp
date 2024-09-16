#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
private:

	Brain *brain;

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
