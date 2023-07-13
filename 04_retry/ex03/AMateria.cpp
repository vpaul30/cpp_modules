#include "AMateria.hpp"

AMateria::AMateria() : _type("materia")
{
	// std::cout << "AMateria default consturctor called.\n";
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	// std::cout << "AMateria consturctor called.\n";
}

AMateria::AMateria(const AMateria &other)
{
	// std::cout << "AMateria copy consturctor called.\n";
	*this = other;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria desturctor called.\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	// std::cout << "AMateria assignment operator called.\n";
	_type = other._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMATERIA USE() on " << target.getName() << std::endl;
}
