#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "The cat has been successfully tamed" << std::endl;
	_brain_of_cat = new Brain();
}

Cat::Cat(const Cat &other)
{
	this->operator=(other);
}

Cat &Cat::operator=(const Cat &other)
{
	this->_type = other._type;
	this->_brain_of_cat = other._brain_of_cat;
	return *this;
}

Cat::~Cat()
{
	delete _brain_of_cat;
	std::cout << "The cat has run wild" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miay" << std::endl;
}