#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int for_sign, int for_execute): _name(name), _is_signed(false), _for_sign(for_sign), _for_execute(for_execute)
{
	if (for_sign < 1 || for_execute < 1)
		throw Form::GradeTooHighException();
	else if (for_sign > 150 || for_execute > 150)
		throw Form::GradeTooLowException();	
}

Form::~Form()
{}

Form::Form(const Form &other): _name(other._name), _is_signed(other._is_signed), _for_sign(other._for_sign), _for_execute(other._for_execute)
{}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	*(const_cast<std::string *>(&_name)) = other.getName();
	*(const_cast<int *>(&_for_sign)) = other.getGradeForSign();
	*(const_cast<int *>(&_for_execute)) = other.getGradeForExecute();
	_is_signed = other.getIsSigned();
	return *this;
}


std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int	Form::getGradeForSign() const
{
	return _for_sign;
}

int Form::getGradeForExecute() const
{
	return _for_execute;
}


void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < _for_sign + 1)
		_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade for form");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade for form");;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " have:\ngrade required to execute = ";
	out << form.getGradeForExecute() << "	\ngrade required to sign = ";
	out << form.getGradeForSign();
	if (form.getIsSigned())
		out << "\nForm is signed" << std::endl;
	else
		out << "\nForm is not signed" << std::endl;
	return (out);
}