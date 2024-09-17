#include "Brain.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;

	for (size_t i = 0; i < 100; i++)
	{
		std::ostringstream buffer;
		buffer << "idea number " << i;
		ideas[i] = buffer.str();
	}
	
}

Brain::Brain(const Brain &model) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = model.ideas[i];
}

Brain &Brain::operator=(const Brain &model) {
	std::cout << "Brain =constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = model.ideas[i];
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

