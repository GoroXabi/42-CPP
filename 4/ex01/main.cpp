#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"


int main()
{
    
const Animal		*animals[100];

for (size_t i = 0; i < 100; i++)
{
	if (i % 2)
    	animals[i] = new Cat();
	else
		animals[i] = new Dog();
}

for (size_t i = 0; i < 100; i++)
	std::cout << animals[i]->get_type() << " " << std::endl;

for (size_t i = 0; i < 100; i++)
	animals[i]->makeSound();

for (size_t i = 0; i < 100; i++)
    	delete animals[i];

return 0;
}
