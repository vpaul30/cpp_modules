#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called.\n";
}

Cure::Cure(const Cure &other)
{
	std::cout << "Cure copy constructor called.\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called.\n";
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure assignment operator called.\n";
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