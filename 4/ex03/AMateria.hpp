#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"


class	AMateria
{
protected:
	//[...]
public:

/*--------------------CONSTRUCTORS-------------------*/
	AMateria();
	AMateria(const AMateria &model);
	AMateria &operator=(const AMateria &model);

/*--------------------DESTRUCTORS--------------------*/

	~AMateria();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	AMateria(std::string const & type);
	//[...]
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

class AMateria
{
public:


};

#endif
