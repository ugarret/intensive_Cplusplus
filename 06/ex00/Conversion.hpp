#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>

class Conversion
{
	private:
		char	_in_char;
		int		_in_int;
		float	_in_float;
		double	_in_double;
		bool	_exp_for_char;
		bool	_exp_for_int;
		void	for_char(char in_char);
		void	for_int(long long int in_int);
		void	for_float(float in_float);
		void	for_double(double in_double);

	public:
		Conversion(char *const &str);
		Conversion(const Conversion&);
		Conversion &operator=(const Conversion&);
		~Conversion();

		char	get_in_char() const;
		int		get_in_int() const;
		float	get_in_float() const;
		double	get_in_double() const;
		bool	get_exp_for_char() const;
		bool	get_exp_for_int() const;

		class NotConvertible: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Conversion const &conv);

#endif