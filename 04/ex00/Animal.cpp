#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(const Animal &other)
{
	this->operator=(other);
}

Animal &Animal::operator=(const Animal &other)
{
	this->_type = other._type;
	return *this;
}

Animal::~Animal()
{
}

void Animal::makeSound() const
{
}

std::string Animal::getType() const
{
	return _type;
}