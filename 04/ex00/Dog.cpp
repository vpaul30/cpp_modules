#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called.\n";
	_type = "Dog";
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

void Dog::makeSound() const
{
	std::cout << "Woof Woof!\n";
}