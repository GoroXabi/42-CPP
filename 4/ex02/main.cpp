#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"


#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"
#define	ARR_SIZE 10


int main()
{
	std::cout << HGRE << "---CONSTRUCTORS---" << std::endl;
    //AAnimal Jose;
	const AAnimal		*animals[ARR_SIZE];

	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << RST << std::endl;
	
	std::cout << HBLU << "---TYPES---" << std::endl;
	for (size_t i = 0; i < ARR_SIZE; i++)
		std::cout << animals[i]->get_type() << " " << std::endl;
	std::cout << RST << std::endl;

	std::cout << HMAG << "---SOUNDS---" << std::endl;
	for (size_t i = 0; i < ARR_SIZE; i++)
		animals[i]->makeSound();
	std::cout << RST << std::endl;

	std::cout << HRED << "---DESTRUCTORS---" << std::endl;
	for (size_t i = 0; i < ARR_SIZE; i++)
			delete animals[i];
	std::cout << RST;
	return 0;
}
