#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called.\n";
	_type = "Dog";
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cout << "Error. Memory allocation.\n";
		std::cout << "Exiting...\n";
		exit(1);
	}
}

Dog::Dog(const Dog &other)
{
	_brain = NULL;
	std::cout << "Dog copy constructor called.\n";
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignement operator called.\n";
	_type = other.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other.getBrain()));
	if (_brain == NULL)
	{
		std::cout << "Error. Memory allocation.\n";
		std::cout << "Exiting...\n";
		exit(1);
	}
	return *this;
}

Animal	&Dog::operator=(Animal const &other)
{
	std::cout << "Animal assignement operator called for dog.\n";
	_type = other.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other.getBrain()));
	if (_brain == NULL)
	{
		std::cout << "Error. Memory allocation.\n";
		std::cout << "Exiting...\n";
		exit(1);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
	delete _brain;
}

Brain *Dog::getBrain() const
{
	return _brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!\n";
}