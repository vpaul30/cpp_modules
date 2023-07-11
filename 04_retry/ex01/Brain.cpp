#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called.\n";
	std::string idea;
	for (int i = 0; i < 100; i++)
	{
		idea = "Brilliant idea number " + std::to_string(i + 1);
		ideas[i] = idea;
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called.\n";

	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called.\n";
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignement operator called.\n";
	
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}
