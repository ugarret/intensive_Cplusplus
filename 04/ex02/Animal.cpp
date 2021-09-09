#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "A wild animal was born" << std::endl;
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
	std::cout << "Wild animal ran away into the forest" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}