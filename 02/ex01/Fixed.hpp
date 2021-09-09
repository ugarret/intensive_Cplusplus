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
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &claas_for_print);

#endif