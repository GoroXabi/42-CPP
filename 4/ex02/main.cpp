#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"


int main()
{
    
//const AAnimal		*meta = new AAnimal();
const Dog		*j = new Dog();
const Cat		*i = new Cat();



std::cout << j->get_type() << " " << std::endl;
std::cout << i->get_type() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();

delete j;
delete i;

return 0;
}
