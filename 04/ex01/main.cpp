#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_new(const Animal *new_animal)
{
	if (new_animal == NULL)
	{
		std::cout << "Error. Memory allocation.\n";
		std::cout << "Exiting...\n";
		exit(1);
	}
}

int main()
{
	std::cout << "=====\n";
	std::cout << "Check if Animal Class is abstract:\n";
	Animal *abstract = new Animal();
	std::cout << "Type: " << abstract->getType() << std::endl;
	delete abstract;
	std::cout << "=====\n";

	std::cout << "=====\n";
	std::cout << "Creating 6 animals (3 cats and 3 dogs):\n";
	const Animal *animal_arr[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
		{
			animal_arr[i] = new Dog();
			check_new(animal_arr[i]);
		}
		else
		{
			animal_arr[i] = new Cat();
			check_new(animal_arr[i]);
		}
	}
	std::cout << "=====\n";

	std::cout << std::endl;

	std::cout << "=====\n";
	std::cout << "Proof of deep copy:\n";
	Animal *dog_copy = new Dog();
	check_new(dog_copy);
	*dog_copy = *(animal_arr[1]);
	std::cout << "\nIdea at index 0 before change:\n";
	std::cout << animal_arr[1]->getBrain()->getIdeas()[0] << std::endl;
	std::cout << dog_copy->getBrain()->getIdeas()[0] << std::endl;
	dog_copy->getBrain()->getIdeas()[0] = "Dog copy with new idea!!!";
	std::cout << "\nIdea at index 0 after change:\n";
	std::cout << animal_arr[1]->getBrain()->getIdeas()[0] << std::endl;
	std::cout << dog_copy->getBrain()->getIdeas()[0] << std::endl;
	std::cout << std::endl;
	delete dog_copy;

	// std::cout << std::endl;
	// Animal *cat_copy = new Cat();
	// check_new(cat_copy);
	// *cat_copy = *(animal_arr[0]);
	// std::cout << "\nIdea at index 0 before change:\n";
	// std::cout << animal_arr[1]->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << cat_copy->getBrain()->getIdeas()[0] << std::endl;
	// cat_copy->getBrain()->getIdeas()[0] = "Cat copy with new idea!!!";
	// std::cout << "\nIdea at index 0 after change:\n";
	// std::cout << animal_arr[1]->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << cat_copy->getBrain()->getIdeas()[0] << std::endl;
	// std::cout << std::endl;
	// delete cat_copy;
	std::cout << "=====\n";

	std::cout << std::endl;

	std::cout << "=====\n";
	std::cout << "Deleting 6 animals (3 cats and 3 dogs):\n";
	for (int i = 0; i < 6; i++)
		delete animal_arr[i];
	std::cout << "=====\n";
	return 0;
}