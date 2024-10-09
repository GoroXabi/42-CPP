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
	Ice(const AMateria &model);
	Ice &operator=(const AMateria &model);

/*--------------------DESTRUCTORS--------------------*/

	~Ice();

/*-----------------PUBLIC_FUNCTIONS------------------*/
	Ice(std::string const & type);
	//[...]
	std::string const & getType() const; //Returns the materia type
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
