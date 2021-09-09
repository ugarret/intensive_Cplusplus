#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool 		_is_signed;
		const int	_for_sign;
		const int	_for_execute;

	public:
		Form(std::string name, const int for_sign, const int for_execute);
		virtual ~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);

		std::string		getName() const;
		bool 			getIsSigned() const;
		int				getGradeForSign() const;
		int				getGradeForExecute() const;
		void			beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class AnotherException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif