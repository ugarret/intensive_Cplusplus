#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	this->operator=(other);
}

Cat &Cat::operator=(const Cat &other)
{
	this->_type = other._type;
	return *this;
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
	std::cout << "Miay" << std::endl;
}