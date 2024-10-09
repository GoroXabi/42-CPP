#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
protected:

	std::string type;

public:

/*--------------------CONSTRUCTORS-------------------*/
	AAnimal();
	AAnimal(const AAnimal &model);
	AAnimal &operator=(const AAnimal &model);

/*--------------------DESTRUCTORS--------------------*/

	virtual ~AAnimal();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string			get_type() const;
	void				set_type(std::string new_type);
	virtual void		makeSound() const = 0;
};

#endif
