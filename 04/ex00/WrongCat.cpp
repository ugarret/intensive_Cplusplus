#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->operator=(other);
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	std::cout << "Miay" << std::endl;
}