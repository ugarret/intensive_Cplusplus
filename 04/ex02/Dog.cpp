#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "The dog has been successfully tamed" << std::endl;
	_brain_of_dog = new Brain();
}

Dog::Dog(const Dog &other)
{
	this->operator=(other);
}

Dog &Dog::operator=(const Dog &other)
{
	this->_type = other._type;
	this->_brain_of_dog = other._brain_of_dog;
	return *this;
}

Dog::~Dog()
{
	delete _brain_of_dog;
	std::cout << "The dog has run wild" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}