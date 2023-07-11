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

	Animal &operator=(const Animal &other);
	Cat &operator=(const Cat &other);
	~Cat();

	Brain *getBrain() const;
	void makeSound() const;
};

#endif