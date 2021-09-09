#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
}

Dog::Dog(const Dog &other)
{
	this->operator=(other);
}

Dog &Dog::operator=(const Dog &other)
{
	this->_type = other._type;
	return *this;
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}