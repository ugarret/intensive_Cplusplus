#include "Conversion.hpp"
#include <limits>
#include <cmath>

#define int_min std::numeric_limits<int>::min()
#define int_max std::numeric_limits<int>::max()
#define char_min std::numeric_limits<char>::min()
#define char_max std::numeric_limits<char>::max()

Conversion::Conversion(char *const &str)//переводим строку в литерал
{
	std::string	temp;
	long long int	to_int;
	size_t		nope = -1;

	temp = static_cast<std::string>(str);
	unsigned int lenght = temp.length();
	_exp_for_char = 0;
	_exp_for_int = 0;

	if (lenght == 1 && !(str[0] >= '0' && str[0] <= '9'))
		this->for_char(str[0]);
	else if (temp == "+inff" || temp == "-inff" || temp == "nanf" || (temp.find(".") != nope && temp[lenght - 1] == 'f'))
		this->for_float(static_cast<float>(atof(str)));
	else if (temp == "+inf" || temp == "-inf" || temp == "nan" || (temp.find(".") != nope))
		this->for_double(atof(str));
	else if (!(to_int = atoll(str)) && (str[0] != '0' || str[1] != '\0'))
		throw NotConvertible();
	else
		this->for_int(to_int);;
}

Conversion::Conversion(const Conversion &other)
{
	this->operator=(other);
}

Conversion::~Conversion()
{}

Conversion &Conversion::operator=(const Conversion &other)
{
	if (this == &other)
		return (*this);
	_in_char = other._in_char;
	_in_int = other._in_int;
	_in_float = other._in_float;
	_in_double = other._in_double;
	_exp_for_char = other._exp_for_char;
	_exp_for_int = other._exp_for_int;
	return (*this);
}

void Conversion::for_char(char in_char)
{
	_in_char = in_char;
	_in_int = static_cast<int>(in_char);
	_in_float = static_cast<float>(in_char);
	_in_double = static_cast<double>(in_char);
}

void Conversion::for_int(long long int in_int)
{
	_in_double = static_cast<double>(in_int);;
	_in_float = static_cast<float>(in_int);
	if (_in_double > int_max || _in_double < int_min)
	{
		_exp_for_char = 1;
		_exp_for_int = 1;
		return ;
	}
	else if (_in_double > char_max || _in_double < char_min)
		_exp_for_char = 1;
	_in_int = in_int;
	_in_char = static_cast<char>(in_int);
}

void Conversion::for_float(float in_float)
{
	_in_float = in_float;
	std::cout << in_float << std::endl;
	_in_double = static_cast<double>(in_float);
	if (std::isinf(_in_double) || std::isnan(_in_double) || _in_double > int_max || _in_double < int_min)
	{
		_exp_for_char = 1;
		_exp_for_int = 1;
		return ;
	}
	else if (_in_double > char_max || _in_double < char_min)
		_exp_for_char = 1;
	_in_char = static_cast<char>(in_float);
	_in_int = static_cast<int>(in_float);
}

void Conversion::for_double(double in_double)
{
	_in_double = in_double;
	_in_float = static_cast<float>(in_double);
	if (std::isinf(_in_double) || std::isnan(_in_double) || _in_double > int_max || _in_double < int_min)
	{
		_exp_for_char = 1;
		_exp_for_int = 1;
		return ;
	}
	else if (_in_double > char_max || _in_double < char_min)
		_exp_for_char = 1;
	_in_char = static_cast<char>(in_double);
	_in_int = static_cast<int>(in_double);
}

char Conversion::get_in_char() const
{
	return (_in_char);
}

int Conversion::get_in_int() const
{
	return (_in_int);
}

float Conversion::get_in_float() const
{
	return(_in_float);
}

double Conversion::get_in_double() const
{
	return(_in_double);
}

bool Conversion::get_exp_for_char() const
{
	return(_exp_for_char);
}

bool Conversion::get_exp_for_int() const
{
	return(_exp_for_int);
}

const char* Conversion::NotConvertible::what() const throw()
{
	return ("The conversion is impossible");
}

std::ostream &operator<<(std::ostream &out, Conversion const &conv)
{
	double fraction = conv.get_in_double() - static_cast<double>(conv.get_in_int()); 
	out << "char: ";
	if (conv.get_exp_for_char())
		out << "impossible" << std::endl;
	else if (conv.get_in_char() < 32 || conv.get_in_char() > 126)
		out << "Non displayable" << std::endl;
	else
		out << "\'" << conv.get_in_char() << "\'" << std::endl;
	out << "int: ";
	if (conv.get_exp_for_int())
		out << "impossible" << std::endl;
	else
		out << conv.get_in_int() << std::endl;
	out << "float: " << conv.get_in_float();
	if (!fraction)
		out << ".0";
	out << "f" << std::endl;
	out << "double: " << conv.get_in_double();
	if (!fraction)
		out << ".0";
	out << std::endl;
	return (out);
}
