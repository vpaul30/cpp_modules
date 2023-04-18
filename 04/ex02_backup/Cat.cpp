#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called.\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called.\n";
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator called.\n";
	_type = other.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain(*(other.getBrain()));
	return *this;
}

Animal	&Cat::operator=(Animal const &other)
{
	std::cout << "Animal assignement operator called for cat.\n";
	_type = other.getType();
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

// void Cat::printBrain() const
// {
// 	std::string *ideas_arr = _brain->getIdeas();

// 	for (int i = 0; i < 100; i++)
// 		std::cout << ideas_arr[i] << std::endl;
// }