#include "ClapTrap.hpp"
#include <sstream>
#include <string>

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

ClapTrap::ClapTrap()
{
	name = "nameless";
	HP = 10;
	EP = 10;
	AD = 10;

std::cout << "ClapTrap default constructor called, name set to " << name << std::endl;
}

ClapTrap::ClapTrap(std::string new_name)
{
	name = new_name;
	HP = 10;
	EP = 10;
	AD = 10;

	std::cout << "ClapTrap constructor(string) called, name set to " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &model)
{
	name = model.name;
	HP = model.HP;
	EP = model.EP;
	AD = model.AD;

	std::cout << "ClapTrap copy constructor called, name set to " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &model)
{
	name = model.name;
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

/*--------------------------------------------------------------*/
/*							GET_FUNCTIONS						*/
/*--------------------------------------------------------------*/


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

/*--------------------------------------------------------------*/
/*							SET_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	ClapTrap::set_name(std::string new_name){
	name = new_name;
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