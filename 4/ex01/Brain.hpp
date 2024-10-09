#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class	Brain
{
private:
	std::string ideas[100];
public:

/*--------------------CONSTRUCTORS-------------------*/
	Brain();
	Brain(const Brain &model);
	Brain &operator=(const Brain &model);

/*--------------------DESTRUCTORS--------------------*/

	~Brain();

/*-----------------PUBLIC_FUNCTIONS------------------*/

	std::string	get_idea(int n);

};

#endif
