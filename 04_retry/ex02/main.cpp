#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// std::cout << "=====\n";
	// std::cout << "Check if Animal Class is abstract:\n";
	// Animal *abstract = new Animal();
	// std::cout << "Type: " << abstract->getType() << std::endl;
	// delete abstract;
	// std::cout << "=====\n";

	std::cout << std::endl;

	std::cout << "=====\n";
	std::cout << "Creating 6 animals (3 cats and 3 dogs):\n";
	const Animal *animal_arr[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			animal_arr[i] = new Dog();
		else
			animal_arr[i] = new Cat();
	}
	std::cout << "=====\n";

	std::cout << std::endl;

	std::cout << "=====\n";
	std::cout << "Proof of deep copy:\n";
	animal_arr[1]->getBrain()->ideas[0] = "Cool idea!";

	Animal *dog_copy = new Dog();
	*dog_copy = *(animal_arr[1]);
	std::cout << "\nIdea at index 0 before change:\n";
	std::cout << "Dog: " << animal_arr[1]->getBrain()->ideas[0] << std::endl;
	std::cout << "Dog copy: " << dog_copy->getBrain()->ideas[0] << std::endl;
	dog_copy->getBrain()->ideas[0] = "Dog copy has a new amazing idea!!!";
	std::cout << "\nIdea at index 0 after change:\n";
	std::cout << "Dog: " << animal_arr[1]->getBrain()->ideas[0] << std::endl;
	std::cout << "Dog copy: " << dog_copy->getBrain()->ideas[0] << std::endl;

	std::cout << std::endl;

	delete dog_copy;

	std::cout << std::endl;
	
	animal_arr[0]->getBrain()->ideas[0] = "Cool idea!";
	Animal *cat_copy = new Cat();
	*cat_copy = *(animal_arr[0]);
	std::cout << "\nIdea at index 0 before change:\n";
	std::cout << "Cat: " << animal_arr[0]->getBrain()->ideas[0] << std::endl;
	std::cout << "Cat copy: " << cat_copy->getBrain()->ideas[0] << std::endl;
	cat_copy->getBrain()->ideas[0] = "Cat copy has a new amazing idea!!!";
	std::cout << "\nIdea at index 0 after change:\n";
	std::cout << "Cat: " << animal_arr[0]->getBrain()->ideas[0] << std::endl;
	std::cout << "Cat copy: " << cat_copy->getBrain()->ideas[0] << std::endl;
	std::cout << std::endl;

	delete cat_copy;
	std::cout << "=====\n";

	std::cout << std::endl;

	std::cout << "=====\n";
	std::cout << "Deleting 6 animals (3 cats and 3 dogs):\n";
	for (int i = 0; i < 6; i++)
		delete animal_arr[i];
	std::cout << "=====\n";
	return 0;
}