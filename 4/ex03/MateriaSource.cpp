#include "MateriaSource.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

MateriaSource::MateriaSource() {
	std::cout << "Materia default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &model) {
	std::cout << "Materia model constructor called" << std::endl;

}

MateriaSource &MateriaSource::operator=(const MateriaSource &model) {
	std::cout << "Materia =constructor called" << std::endl;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

MateriaSource::~MateriaSource() {
	std::cout << "Materia default destrucotr called" << std::endl;
}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	MateriaSource::learnMateria(AMateria* new_materia) {
	for (size_t i = 0; i < 3; i++)
	{
		if (!learned[i])
		{
			learned[i] = new_materia;
			return ;
		}
	}
	

}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 3; i++)
	{
		if (learned[i] && learned[i]->getType() == type)
			return(learned[i]->clone());
	}
	std::cout << "Materia type is unknown!" << std::endl;
	return (0);
	

}