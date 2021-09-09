#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->operator=(other);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
}

void WrongAnimal::makeSound() const
{
}

std::string WrongAnimal::getType() const
{
	return _type;
}