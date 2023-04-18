#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string *ideas;
public:
	Brain();
	Brain(const Brain &other);
	
	~Brain();

	std::string *getIdeas() const;
};

#endif