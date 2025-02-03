#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"
#define	ARR_SIZE 10


int main()
{
	std::cout << HGRE << "---CONSTRUCTORS---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << RST << std::endl;

	std::cout << HBLU << "---ACTIONS---" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << RST << std::endl;
	
	std::cout << HRED << "---DESTRUCTORS---" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << RST;
	return 0;
}