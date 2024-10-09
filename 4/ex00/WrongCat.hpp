#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"


class	WrongCat: public WrongAnimal
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	WrongCat();
	WrongCat(const WrongCat &model);
	WrongCat &operator=(const WrongCat &model);

/*--------------------DESTRUCTORS--------------------*/

	~WrongCat();
	
/*-----------------PUBLIC_FUNCTIONS------------------*/

	void						makeSound() const;
};

#endif
