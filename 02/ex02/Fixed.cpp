#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_point_value)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(int_point_value * (1 << _fractional_bits));
}

Fixed::Fixed(const float floating_point_value)
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(floating_point_value * (1 << _fractional_bits))); // умножаем на 256
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _fractional_bits)); // делим на 256
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() / (1 << _fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_fixed_point_value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &fd, const Fixed &class_for_print)
{
	fd << class_for_print.toFloat();
	return fd;
}


bool Fixed::operator>(const Fixed &other)
{
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other)
{
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other)
{
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other)
{
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other)
{
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other)
{
	return this->toFloat() != other.toFloat();
}

float Fixed::operator+(const Fixed &other)
{
	return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other)
{
	return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other)
{
	return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other)
{
	return this->toFloat() / other.toFloat();
}

Fixed Fixed::operator++()
{
	this->setRawBits(++this->_fixed_point_value);
	return *this;
}

Fixed Fixed::operator++(int value)
{
	value = 0;
	Fixed new_fix(this->toFloat());
	this->setRawBits(++this->_fixed_point_value);
	return new_fix;
}

Fixed Fixed::operator--()
{
	this->setRawBits(--this->_fixed_point_value);
	return *this;
}

Fixed Fixed::operator--(int value)
{
	value = 0;
	Fixed new_fix(this->toFloat());
	this->setRawBits(--this->_fixed_point_value);
	return new_fix;
}

Fixed Fixed::max(Fixed &first, Fixed &second)
{
	return first._fixed_point_value > second._fixed_point_value ? first : second;
}

Fixed Fixed::max(Fixed const &first, Fixed const &second)
{
	return first._fixed_point_value > second._fixed_point_value ? first : second;
}

Fixed Fixed::min(Fixed &first, Fixed &second)
{
	return first._fixed_point_value < second._fixed_point_value ? first : second;
}

Fixed Fixed::min(Fixed const &first, Fixed const &second)
{
	return first._fixed_point_value < second._fixed_point_value ? first : second;
}