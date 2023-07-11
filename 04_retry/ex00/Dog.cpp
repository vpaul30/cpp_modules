#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called.\n";
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called.\n";
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignement operator called.\n";
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!\n";
}