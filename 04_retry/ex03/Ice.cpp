#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice default constructor called.\n";
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	// std::cout << "Ice copy constructor called.\n";
	*this = other;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called.\n";
}

Ice &Ice::operator=(const Ice &other)
{
	// std::cout << "Ice assignment operator called.\n";
	if (_type == other._type)
		return *this;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}