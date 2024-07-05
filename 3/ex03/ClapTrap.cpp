#include "ClapTrap.hpp"
#include <sstream>
#include <string>

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ClapTrap::ClapTrap()
{
	name = "Nameless";
	monster_type = "ClapTrap";
	HP = 10;
	EP = 10;
	AD = 10;

std::cout << "ClapTrap default constructor called, name set to " << name << std::endl;
}

ClapTrap::ClapTrap(std::string new_name)
{
	name = new_name;
	monster_type = "ClapTrap";
	HP = 10;
	EP = 10;
	AD = 10;

	std::cout << "ClapTrap constructor(string) called, name set to " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &model)
{
	name = model.name;
	monster_type = model.monster_type;
	HP = model.HP;
	EP = model.EP;
	AD = model.AD;

	std::cout << "ClapTrap copy constructor called, name set to " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &model)
{
	name = model.name;
	monster_type = model.monster_type;
	HP = model.HP;
	EP = model.EP;
	AD = model.AD;

	std::cout << "ClapTrap =constructor called, name set to " << name << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

ClapTrap::~ClapTrap() {

	std::cout << "ClapTrap desctructor for " << name <<" called" << std::endl;

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

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/


std::string	ClapTrap::get_name() const {
	return(name);
}

std::string	ClapTrap::get_type() const {
	return(monster_type);
}

int	ClapTrap::get_HP() const {
	return(HP);
}

int	ClapTrap::get_AD() const {
	return(AD);
}

int	ClapTrap::get_EP() const {
	return(EP);
}

/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	ClapTrap::set_name(std::string new_name){
	name = new_name;
}

void	ClapTrap::set_type(std::string new_type){
	monster_type = new_type;
}

void	ClapTrap::set_HP(int new_HP){
	HP = new_HP;
}

void	ClapTrap::set_AD(int new_AD){
	AD = new_AD;
}

void	ClapTrap::set_EP(int new_EP){
	EP = new_EP;
}