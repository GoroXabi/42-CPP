#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    
const Animal		*meta = new Animal();
const Animal		*j = new Dog();
const Animal		*i = new Cat();
const WrongAnimal	*k = new WrongCat();



std::cout << j->get_type() << " " << std::endl;
std::cout << i->get_type() << " " << std::endl;
std::cout << k->get_type() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
k->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;
delete k;

return 0;
}
