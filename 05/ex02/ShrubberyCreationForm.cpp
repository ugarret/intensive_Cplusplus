#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreation", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): Form(other)
{
	this->_target = other.getTarget();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	this->_target = other.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const 
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw Form::NotSignedException();
	else if (bureaucrat.getGrade() > this->getGradeForExecute())
		throw Form::GradeTooLowException();
	std::ofstream out(std::string(this->getTarget() + "_shrubbery").c_str());
	if (out.is_open())
	{
			out <<	"    _\\/_\n"
					"     /\\\n"
					"     /\\\n"
					"    /  \\\n"
					"    /~~\\@\n"
					"   /@   \\\n"
					"  /~~*~~~\\\n"
					" @/    @ \\\n"
					" /~~~~~~~~\\~`\n"
					"/__*_______\\\n"
					"     ||\n"
					"   (\\___/)\n"
					"   (='.'=)\n"
					"   (\")_(\")\n" << std::endl;
		out.close();
	}
	else
		throw Form::AnotherException();
}
