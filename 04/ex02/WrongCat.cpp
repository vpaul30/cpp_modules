#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called.\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat copy constructor called.\n";
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Mooo!\n";
}