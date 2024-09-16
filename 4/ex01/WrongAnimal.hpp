#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
private:

	std::string type;

public:

/*--------------------CONSTRUCTORS-------------------*/
	WrongAnimal();
	WrongAnimal(const WrongAnimal &model);
	WrongAnimal &operator=(const WrongAnimal &model);

/*--------------------DESTRUCTORS--------------------*/

	virtual ~WrongAnimal();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string					get_type() const;

	void						set_type(std::string new_type);
	virtual void				makeSound() const;
};

#endif
