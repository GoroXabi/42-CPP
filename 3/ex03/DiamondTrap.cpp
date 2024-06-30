#include "DiamondTrap.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

DiamondTrap::DiamondTrap() {
	name = "nameless";
	ClapTrap::set_name("nameless_clap_name");
	ClapTrap::set_HP(10);
}

DiamondTrap::DiamondTrap(const DiamondTrap &model) {

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &model) {
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

DiamondTrap::~DiamondTrap() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

