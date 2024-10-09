#include <iostream>
#include <iomanip>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"


int main()
{
	std::cout << HGRE  << "---CONSTRUCTORS---" << std::endl;
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();
	const WrongCat		*l = new WrongCat();
	std::cout << RST << std::endl;

	std::cout << HBLU << "---TYPES---" << std::endl;
	std::cout << j->get_type() << std::endl;
	std::cout << i->get_type() << std::endl;
	std::cout << k->get_type() << std::endl;
	std::cout << l->get_type() << std::endl;
	std::cout << meta->get_type() << std::endl;
	std::cout << RST << std::endl;

	std::cout << HMAG << "---SOUNDS---" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	l->makeSound();
	meta->makeSound();
	std::cout << RST << std::endl;

	std::cout << HRED << "---DESTRUCTORS---" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete k;
	std::cout << RST;

	return 0;
}
