#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"


class	AMateria
{
protected:

	std::string type;

public:

/*--------------------CONSTRUCTORS-------------------*/

	AMateria();
	AMateria(const AMateria &model);
	AMateria &operator=(const AMateria &model);
	AMateria(std::string const & type);

/*--------------------DESTRUCTORS--------------------*/

	virtual ~AMateria() {};

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif
