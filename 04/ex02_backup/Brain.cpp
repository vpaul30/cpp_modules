#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called.\n";
	ideas = new std::string[100];
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
	ideas = new std::string[100];
	std::string *other_ideas = other.getIdeas();

	for (int i = 0; i < 100; i++)
		ideas[i] = other_ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called.\n";
	delete []ideas;
}

std::string *Brain::getIdeas() const
{
	return ideas;
}