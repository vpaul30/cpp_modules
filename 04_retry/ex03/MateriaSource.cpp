#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{

	// std::cout << "MateriaSource default constructor called.\n";
	for (int i = 0; i < 4; i++)
		_knownMaterias[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	// std::cout << "MateriaSource copy constructor called.\n";
	*this = other;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called.\n";
	for (int i = 0; i < 4; i++)
		if (_knownMaterias[i] != NULL)
			delete _knownMaterias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	// std::cout << "MateriaSource assignment operator called.\n";
	for (int i = 0; i < 4; i++)
		if (_knownMaterias[i] != NULL)
			delete _knownMaterias[i];

	for (int i = 0; i < 4; i++)
		_knownMaterias[i] = other._knownMaterias[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	// copies the materia and stores it
	for (int i = 0; i < 4; i++)
	{
		if (_knownMaterias[i] == NULL)
		{
			_knownMaterias[i] = m->clone();
			delete m;
			return;
		}
	}
	std::cout << "* there are already 4 Materias in MateriaSource *\n";
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_knownMaterias[i] && _knownMaterias[i]->getType() == type)
			return _knownMaterias[i]->clone();
	std::cout << "* MateriaSource doesn't know " << type << " Materia *\n";
	return NULL;
}