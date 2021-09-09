#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int int_point_value);
		Fixed(const float floating_point_value);
		Fixed(const Fixed &other);					//Конструктор копирования
		~Fixed();

		Fixed	&operator=(const Fixed &other);		//Перегрузка оператора присваивания
		float	operator+(const Fixed &other);
		float	operator-(const Fixed &other);
		float	operator*(const Fixed &other);
		float	operator/(const Fixed &other);
		Fixed	operator++();
		Fixed	operator++(int value);
		Fixed	operator--();
		Fixed	operator--(int value);

		bool	operator==(const Fixed &other);
		bool	operator!=(const Fixed &other);
		bool	operator>(const Fixed &other);
		bool	operator>=(const Fixed &other);
		bool	operator<(const Fixed &other);
		bool	operator<=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static 	Fixed max(Fixed &first, Fixed &second);
		static 	Fixed max(Fixed const &first, Fixed const &second);
		static 	Fixed min(Fixed &first, Fixed &second);
		static 	Fixed min(Fixed const &first, Fixed const &second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &claas_for_print);

#endif