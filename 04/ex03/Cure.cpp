#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	_type = "cure";
	std::cout << _type << " сreated" << std::endl;
}

Cure::~Cure()
{
	std::cout << _type << " destroyed" << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria *mat = new Cure();
	return mat;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}