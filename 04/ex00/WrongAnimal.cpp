#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called.\n";
	*this = other; 
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called.\n";
	_type = other.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called.\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "Weird sound by WrongAnimal.\n";
}

std::string WrongAnimal::getType() const
{
	return _type;
}