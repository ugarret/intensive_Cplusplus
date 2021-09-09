#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	_type = "ice";
	std::cout << _type << " сreated" << std::endl;
}

Ice::~Ice()
{
	std::cout << _type << " destroyed" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *mat = new Ice();
	return mat;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}