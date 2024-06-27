#include "ClapTrap.hpp"
#include <sstream>
#include <string>

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ClapTrap::ClapTrap()
{
	name = "";
	HP = 10;
	EP = 10;
	AD = 10;

std::cout << "default constructor called, name set to \"\"" << std::endl;
}

ClapTrap::ClapTrap(std::string new_name)
{
	name = new_name;
	HP = 10;
	EP = 10;
	AD = 10;

std::cout << "constructor(string) called, name set to " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &model)
{
	name = model.name;
	HP = model.HP;
	EP = model.EP;
	AD = model.AD;

std::cout << "copy constructor called, name set to " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &model)
{
	name = model.name;
	HP = model.HP;
	EP = model.EP;
	AD = model.AD;

std::cout << "=constructor called, name set to " << name << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

ClapTrap::~ClapTrap() {

std::cout << "desctructor for " << name <<" called" << std::endl;

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	ClapTrap::attack(const std::string& target)
{
	if (EP == 0) {
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
		return ;
	}
	if (HP == 0) {
		std::cout << "ClapTrap " << name << " has no HP left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " atacks " << target << 
	", causing " << AD << " points of damage!" << std::endl;
	EP--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << 
	" of damage, cousing its HP to get from " << HP;
	HP -= amount;
	std::cout << " to " << HP << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (EP == 0) {
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
		return ;
	}
	if (HP == 0) {
		std::cout << "ClapTrap " << name << " has no HP left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
	<< "HP getting it from " << HP;
	HP += amount;
	EP--;
	std::cout << " to " << HP << std::endl;
}

void	print_col(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << str.substr(0, 9) << ".";
	else 
		std::cout << "|" << std::setw(10) << std::left << str;
}

void ClapTrap::showInfo()
{
	std::string			monster_type = "ClapTrap";
	std::stringstream	int_str;

	std::cout << "\n" << name << " estatus:" << std::endl;

	std::cout << "|   TYPE   |   NAME   |HIT POINTS|  ENERGY  | ATACK DMG |" << std::endl;
	print_col(monster_type);
	print_col(name);
	int_str << HP;
	print_col(int_str.str());
	int_str.str("");
	int_str << EP;
	print_col(int_str.str());
	int_str.str("");
	int_str << AD;
	print_col(int_str.str());
	std::cout << " |" << std::endl;
}

std::string	ClapTrap::get_name(){
	return(name);
}

int	ClapTrap::get_HP(){
	return(HP);
}

int	ClapTrap::get_AD(){
	return(AD);
}

int	ClapTrap::get_EP(){
	return(EP);
}
