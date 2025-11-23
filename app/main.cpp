#include "app.h"
#include <iostream>	
// read animal id's (until 0) and display species name
// display total leg count

/*
Implementirajte klase potrebne da svi testovi prolaze.
Napišite program koji koristeći te klase :
	unosi šifre životinja(cijeli broj) dok se ne unese 0 i ispisuje naziv vrste svake životinje
	na kraju ispiše ukupan broj nogu životinja
*/

int main()
{
	int id = 0;
	vsite::oop::v4::leg_counter counter;
	do
	{
		std::cout << "Enter animal id (1 to 3) (0 to end): ";
		std::cin >> id;

		if ((id < 1 || id > 3) && id != 0){
			std::cout << "Invalid id!" << std::endl;
		continue;
		}

		auto animal = vsite::oop::v4::animal_factory(id);
		std::string species = counter.add_animal(animal.get());
	} while (id != 0);
	
	std::cout << "Total legs: " << counter.legs() << std::endl;
}
