#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
private:

	Brain *brain;

public:

/*--------------------CONSTRUCTORS-------------------*/
	Cat();
	Cat(const Cat &model);
	Cat &operator=(const Cat &model);

/*--------------------DESTRUCTORS--------------------*/

	~Cat();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	void	makeSound() const;

};

#endif
