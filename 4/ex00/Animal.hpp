#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	
protected:

	std::string type;

public:

/*--------------------CONSTRUCTORS-------------------*/
	Animal();
	Animal(const Animal &model);
	Animal &operator=(const Animal &model);

/*--------------------DESTRUCTORS--------------------*/

	virtual ~Animal();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string					get_type() const;

	void						set_type(std::string new_type);
	virtual void				makeSound() const;
};

#endif
