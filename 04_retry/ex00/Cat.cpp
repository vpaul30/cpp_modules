#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called.\n";
	type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called.\n";
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator called.\n";
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meoow!\n";
}
