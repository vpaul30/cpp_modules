#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called.\n";
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called.\n";
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called.\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator called.\n";
	//
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "MATERIASOURCE CREATEMATERIA()\n";
	// return new Cure;
	return new Ice;
}