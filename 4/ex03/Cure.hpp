#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"


class	Cure: public AMateria
{
protected:
	//[...]
public:

/*--------------------CONSTRUCTORS-------------------*/
	Cure();
	Cure(const Cure &model);
	Cure &operator=(const Cure &model);

/*--------------------DESTRUCTORS--------------------*/

	~Cure();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	Cure(std::string const & type);
	//[...]
	std::string const & getType() const; //Returns the materia type
	virtual Cure* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif
