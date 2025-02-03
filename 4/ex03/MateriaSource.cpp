#include "MateriaSource.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		learned[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &model) {
	for (size_t i = 0; i < 4; i++)
		learned[i] = model.learned[i]->clone();
	std::cout << "MateriaSource model constructor called" << std::endl;

}

MateriaSource &MateriaSource::operator=(const MateriaSource &model) {
	for (size_t i = 0; i < 4; i++)
		learned[i] = model.learned[i]->clone();
	std::cout << "MateriaSource =constructor called" << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		if (learned[i])
			delete learned[i];
	std::cout << "MateriaSource default destructor called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	MateriaSource::learnMateria(AMateria* new_materia) {
	for (size_t i = 0; i < 4; i++)
		if (!learned[i])
		{
			learned[i] = new_materia;
			return ;
		}
}

AMateria *MateriaSource::createMateria(std::string const & type) {


	for (size_t i = 0; i < 4; i++)
		if (learned[i] && learned[i]->getType() == type)
			return(learned[i]->clone());
	std::cout << "Materia type is unknown!" << std::endl;
	return (0);
	

}