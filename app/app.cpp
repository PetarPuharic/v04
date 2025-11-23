#include "app.h"
#include <algorithm>

namespace vsite::oop::v4
{
	// Factory funkcija koja vraća unique_ptr na animal
	std::unique_ptr<animal> animal_factory(int id)
	{
		switch (id)
		{
		case 1:
			return std::make_unique<cockroach>();
		case 2:
			return std::make_unique<sparrow>();
		case 3:
			return std::make_unique<tarantula>();
		default:
			return nullptr;
		}
	}

	// Definija species
	std::string cockroach::species() const
	{
		return "cockroach";
	}
	std::string sparrow::species() const
	{
		return "sparrow";
	}
	std::string tarantula::species() const
	{
		return "tarantula";
	}

	// Definicija legs
	unsigned int insect::legs() const
	{
		return 6u;
	}
	unsigned int bird::legs() const
	{
		return 2u;
	}
	unsigned int spider::legs() const
	{
		return 8u; // u -> unsigned
	}


	// Leg_Count
	std::string leg_counter::add_animal(const animal* a)
	{
		if (a) // provjera da li je pokazivac null
		{
			total_legs += a->legs(); // -> dereferenciranje pokazivaca
			return a->species(); 
		}
		return ""; // vrati prazan string ako je null
	}

	unsigned int leg_counter::legs() const
	{
		return total_legs;
	}
}