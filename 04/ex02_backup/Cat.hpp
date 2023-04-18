#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &other);

	Cat &operator=(const Cat &other);
	Animal &operator=(const Animal &other);
	~Cat();

	Brain *getBrain() const;
	virtual void makeSound() const;
	// void printBrain() const;
};

#endif