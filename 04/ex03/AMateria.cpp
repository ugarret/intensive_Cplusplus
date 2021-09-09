#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	_type = "";
	std::cout << "Default Amateria сreated" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
	std::cout << _type << " сreated" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	this->operator=(other);
}

AMateria &AMateria::operator=(AMateria const &other)
{
	this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Default Amateria destroyed" << std::endl;
}

std::string const &AMateria::getType() const //Returns the materia type
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	target.getName();
}