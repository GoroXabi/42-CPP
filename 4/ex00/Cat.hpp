#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class	Cat: public Animal
{
private:

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
