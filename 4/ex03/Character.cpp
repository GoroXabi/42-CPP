#include "Character.hpp"

Character::Character() {
	name = "Hero";
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character default constructor called, name set to " << name << std::endl;
}

Character::Character(std::string const &new_name) {
	name = new_name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character name constructor called, name set to " << name << std::endl;
}

Character::Character(const Character &model) {
	name = model.name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = model.inventory[i]->clone();
	std::cout << "Character model constructor called, name set to " << name << std::endl;

}

Character &Character::operator=(const Character &model) {
	name = model.name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = model.inventory[i]->clone();
	std::cout << "Character =constructor called, name set to " << name << std::endl;
	return (*this);
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
	std::cout << "Character default destructor called" << std::endl;

}

std::string const &Character::getName() const {
	return(name);
}

void	Character::equip(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
}

void	Character::unequip(int idx) {
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	inventory[idx]->use(target);
}