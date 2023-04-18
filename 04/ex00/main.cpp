#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Main Tests:\n\n";
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound(); //will output the cat sound!

	delete animal;
	delete dog;
	delete cat;

	std::cout << "\nWrongAnimal Tests:\n\n";
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	std::cout << "\nExtra Tests:\n\n";
	Dog another_dog = Dog();
	Cat another_cat = Cat();
	std::cout << another_dog.getType() << std::endl;
	std::cout << another_cat.getType() << std::endl;
	another_dog.makeSound();
	another_cat.makeSound();

	return 0;
}