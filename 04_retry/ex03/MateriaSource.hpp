#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_knownMaterias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif