#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called.\n";
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	// std::cout << "Cure copy constructor called.\n";
	*this = other;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called.\n";
}

Cure &Cure::operator=(const Cure &other)
{
	// std::cout << "Cure assignment operator called.\n";
	if (_type == other._type)
		return *this;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}