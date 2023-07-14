#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called.\n";
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal()
{
	_brain = NULL;
	std::cout << "Cat copy constructor called.\n";
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called.\n";
	type = other.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other.getBrain()));
	return *this;
}

Animal	&Cat::operator=(Animal const &other)
{
	std::cout << "Animal assignment operator called for cat.\n";
	type = other.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other.getBrain()));
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
	delete _brain;
}

Brain *Cat::getBrain() const
{
	return _brain;
}

void Cat::makeSound() const
{
	std::cout << "Meoow!\n";
}