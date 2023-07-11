#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// TODO : MateriaSource, (Character copy, Character destroy)?


// shoots an ice bolt at bob
// heals bob's wounds
AMateria *materiasOnFloor[100];
int materiasOnFloorIdx = 0;

int main()
{
	AMateria *ice = new Ice;
	AMateria *ice2 = new Ice;
	AMateria *ice3 = new Ice;
	AMateria *ice4 = new Ice;

	AMateria *cure = new Cure;
	ICharacter *mike = new Character("Mike");
	ICharacter *bob = new Character("Bob");

	mike->equip(ice);
	mike->equip(cure);
	mike->equip(ice);
	mike->equip(ice2);
	mike->equip(ice3);
	mike->equip(ice4);

	mike->use(0, *bob);

	mike->unequip(2);
	std::cout << "Amount of materias on the floor: " << materiasOnFloorIdx << std::endl;
	std::cout << "Last unequipped material is " << materiasOnFloor[materiasOnFloorIdx - 1]->getType() << std::endl;

	mike->equip(ice4);

	delete ice;
	delete cure;
	delete mike;
	std::cout << "======\n\n";

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}