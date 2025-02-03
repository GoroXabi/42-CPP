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
	Cure(std::string const & type);
	Cure &operator=(const Cure &model);

/*--------------------DESTRUCTORS--------------------*/

	~Cure();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	//[...]
	std::string const & getType() const; //Returns the materia type
	Cure* clone() const;
	void use(ICharacter& target) ;
};


#endif
