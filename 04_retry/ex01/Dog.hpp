#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &other);

	Animal &operator=(const Animal &other);
	Dog &operator=(const Dog &other);
	~Dog();

	Brain *getBrain() const;
	void makeSound() const;
};

#endif