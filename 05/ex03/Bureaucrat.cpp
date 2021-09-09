#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	*(const_cast<std::string*>(&_name)) = other.getName();
	_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increaseGrade()
{
	--(this->_grade);
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	++(this->_grade);
	if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
		std::cout << _name << " cannot sign " << form.getName() << " because Form is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << _name << " signs " << form.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << _name << " cannot sign " << form.getName() << " because ";
			std::cout << e.what() << std::endl;
		}
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot executes " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade for bureaucrat");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too high grade for bureaucrat");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
