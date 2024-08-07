#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"



void	print_hero_col(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << str.substr(0, 9) << ".";
	else 
		std::cout << "|" << std::setw(10) << std::left << str;
}

void showHeroInfo(int HP, int AD, std::string name)
{
	std::string			monster_type = "Hero";
	std::stringstream	int_str;

	std::cout << "\n" << name << " estatus:" << std::endl;

	std::cout << "|   TYPE   |   NAME   |HIT POINTS|  ENERGY  | ATACK DMG |" << std::endl;
	print_hero_col(monster_type);
	print_hero_col(name);
	int_str << HP;
	print_hero_col(int_str.str());
	print_hero_col("INFINITE");
	int_str.str("");
	int_str << AD;
	print_hero_col(int_str.str());
	std::cout << " |" << std::endl;
}

int main()
{
	std::system("clear");
	std::string prompt;
	std::string	hero_name;
	DiamondTrap enemy("Jonh");
	int			hero_AD;
	int			hero_HP;
	bool		hero_def = false;

	hero_HP = 100;
	hero_AD = 30;

	std::cout << "WELCOME TO HERO'S ADVENTURES!" << std::endl;
	std::cout << "WHATS YOUR NAME?" << std::endl;
	std::getline(std::cin, hero_name);
	std::system("clear");

	std::cout << "Watch out! a wild " << enemy.get_type() << " named " << enemy.get_name() << " appeared!" << std::endl;
	while (1)
	{
		std::cout << "\nENTER A COMMAND:" << "\nATACK" << "     DEFEND" << "     INFO" << std::endl;
		std::getline(std::cin, prompt);
		while (prompt != "ATACK" && prompt != "DEFEND" && prompt != "INFO")
		{
			std::cout << "NOT A VALID COMMAND SOWRY" << std::endl;
			std::getline(std::cin, prompt);
		}
		std::system("clear");
		if (prompt == "INFO")
			enemy.showInfo();
		if (prompt == "ATACK")
		{
			std::cout << "The hero attacks!" << std::endl;
			enemy.takeDamage(hero_AD);
		}
		if (prompt == "DEFEND")
		{
			std::cout << hero_name << " will defend it self!" << std::endl;
			hero_def = true;
		}
		if (prompt != "INFO")
		{
			if (enemy.get_EP() <= 0)
				std::cout << enemy.get_name() << " has no energy left!" << std::endl;
			else if (enemy.get_HP() < 20)
				enemy.beRepaired(15);
			else
			{
				enemy.attack(hero_name);
				if (hero_def == true)
				{
					std::cout << "The Hero was defending! it took a third of the damage" << std::endl;
					hero_HP -= enemy.get_AD() / 3;
				}
				else 
					hero_HP -= enemy.get_AD();	
				hero_def = false;
			}
		}
		if (enemy.get_HP() <= 0)
		{
			enemy.whoAmI();
			std::cout << enemy.get_name() << " WAS DEFEATED!!!" << std::endl;
			std::cout << "YOU WIN!!!" << std::endl;
			return (0);
		}
		if (hero_HP <= 0)
		{
			std::cout << enemy.get_name() << " DEALED FATAL DAMAGE" << std::endl;
			std::cout << "YOU LOST!!!" << std::endl;
			return (0);
		}
		showHeroInfo(hero_HP, hero_AD, hero_name);
	}
    return 0;
}
