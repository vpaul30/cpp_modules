#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria *materiasOnFloor[100];
int materiasOnFloorIdx = 0;

int main()
{	

	//* shoots an ice bolt at bob *
	// * heals bob's wounds *

	// === PDF ==
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;

		// clear floor (not needed for pdf example)
		for (int i = 0; i < materiasOnFloorIdx; i++)
			delete materiasOnFloor[i];
		materiasOnFloorIdx = 0;
	}

	// === Tests ===
	{
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// src->learnMateria(new Ice()); // MateriaSource can store up to 4 materias

		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// tmp = src->createMateria("something"); // invalid materia type
		// me->equip(tmp); // tmp is NULL, so equip will do nothing
		
		// ICharacter* bob = new Character("bob");

		// me->use(0, *bob);
		// me->use(1, *bob);
		// me->use(2, *bob); // character doesn't have any materia at index 2
		// tmp = src->createMateria("cure");
		// me->equip(tmp); // now character has cure at index 2
		// me->use(2, *bob);
		// me->unequip(3); // nothing to unequip at index 3
		// me->unequip(2);
		// me->use(2, *bob); // character just unequiped slot 2, so nothing to use

		// delete bob;
		// delete me;
		// delete src;

		// // clear floor
		// for (int i = 0; i < materiasOnFloorIdx; i++)
		// 	delete materiasOnFloor[i];
		// materiasOnFloorIdx = 0;
	}

	// === Deep copy ===
	{
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// ICharacter* bob = new Character("bob");
		// AMateria* tmp;
		
		// std::cout << "=== me ===\n";
		// ICharacter* me = new Character("me");
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// me->use(0, *bob);
		// me->use(1, *bob);

		// std::cout << "\n=== not_me ===\n";
		// ICharacter* not_me = new Character("not me");
		// tmp = src->createMateria("cure");
		// not_me->equip(tmp);
		// not_me->use(0, *bob);
		// not_me->use(1, *bob);

		// std::cout << "\n=== not_me = me ===\n";
		// *(Character *)not_me = *(Character *)me;
		// std::cout << "'not_me' is now '" << not_me->getName() << "'\n";
		// not_me->use(0, *bob);
		// not_me->use(1, *bob);

		// std::cout << "=== not_me equips cure material at index 2\n";
		// tmp = src->createMateria("cure");
		// not_me->equip(tmp);

		// std::cout << "=== me ===\n";
		// me->use(0, *bob);
		// me->use(1, *bob);
		// me->use(2, *bob);

		// std::cout << "=== not_me ===\n";
		// not_me->use(0, *bob);
		// not_me->use(1, *bob);
		// not_me->use(2, *bob);

		// delete bob;
		// delete me;
		// delete not_me;
		// delete src;

		// // clear floor
		// for (int i = 0; i < materiasOnFloorIdx; i++)
		// 	delete materiasOnFloor[i];
		// materiasOnFloorIdx = 0;
	}
	return 0;
}