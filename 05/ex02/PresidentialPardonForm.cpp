#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardon", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): Form(other)
{
	this->_target = other.getTarget();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	this->_target = other.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const 
{
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	else if (bureaucrat.getGrade() > this->getGradeForExecute())
		throw Form::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}