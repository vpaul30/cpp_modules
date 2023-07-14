#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called.\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called.\n";
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment operator called.\n";
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Mooo!\n";
}