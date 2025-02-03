#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"


class	Ice : public AMateria
{
protected:
	//[...]
public:

/*--------------------CONSTRUCTORS-------------------*/
	Ice();
	Ice(const Ice &model);
	Ice(std::string const & type);
	Ice &operator=(const Ice &model);

/*--------------------DESTRUCTORS--------------------*/

	~Ice();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	//[...]
	std::string const & getType() const; //Returns the materia type
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
