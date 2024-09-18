#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMaterialSource.hpp"


class MateriaSource: public IMateriaSource
{
private:

	AMateria *learned[4];

public:

	MateriaSource();

	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	
};

#endif
