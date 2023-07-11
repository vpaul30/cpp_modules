#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);

	virtual Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const;
	virtual Brain *getBrain() const;

	std::string getType() const;
};

#endif