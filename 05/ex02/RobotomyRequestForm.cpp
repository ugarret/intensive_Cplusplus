#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <time.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequest", 72, 45)
{
	_target = target;
	srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): Form(other)
{
	this->_target = other.getTarget();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	this->_target = other.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const 
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	else if (bureaucrat.getGrade() > this->getGradeForExecute())
		throw Form::GradeTooLowException();
	if (rand() % 2)
		std::cout << "DRRRRRRRR\n" << _target << " has been robotomized successfully" << std::endl;
	else
		throw Form::AnotherException();
}
