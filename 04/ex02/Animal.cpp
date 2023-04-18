#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called.\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called.\n";
	*this = other; 
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignement operator called.\n";
	_type = other.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called.\n";
}

void Animal::makeSound() const
{
	std::cout << "Weird sound by animal.\n";
}

// Brain *Animal::getBrain() const
// {
// 	std::cout << "Error. Cannot get brain of Animal, as it does not have one!\n";
// 	std::cout << "Exiting...\n";
// 	exit(1);
// 	return NULL;
// }

std::string Animal::getType() const
{
	return _type;
}
