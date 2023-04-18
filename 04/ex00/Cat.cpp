#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called.\n";
	_type = "Cat";
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

void Cat::makeSound() const
{
	std::cout << "Meoow!\n";
}
