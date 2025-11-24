#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v4
{
	class animal {
	public:
		// virtual za baseline class
		virtual std::string species() const = 0; //const jer se nebi trebalo mijenjati stanje objekta
		virtual unsigned int legs() const = 0;
		virtual ~animal() = default; // virtualni destruktor za brisanje
	};
	
	
	// Test trazi 3 subklase: insect, spider, bird
	// Override metode legs() u svakoj od njih, te dodati virtualni destruktor
	class insect : public animal 
	{
	public:
		unsigned int legs() const override;
	};
	class bird : public animal
	{
	public:
		unsigned int legs() const override;
	};
	class spider : public animal
	{
	public:
		unsigned int legs() const override;
	};



	// Test trazi 3 konkretne klase: cockroach, tarantula, sparrow
	// Override metode species() u svakoj od njih 
	class cockroach : public insect {
	public:
		std::string species() const override;
	};
	
	class sparrow : public bird {
	public:
		std::string species() const override;
	};

	class tarantula : public spider {
	public:
		std::string species() const override;
	};
	


	// Factory funkcija koja vraća unique_ptr na animal
	std::unique_ptr<animal> animal_factory(int id);


	class leg_counter {
		unsigned int total_legs = 0;
	public:
		std::string add_animal(const animal* a);
		unsigned int legs() const;
	};	
}