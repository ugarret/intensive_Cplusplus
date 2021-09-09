#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &) 
{}

Intern	&Intern::operator=(const Intern &)
{
	return *this;
}

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string forms_for_creation[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i <= 2; ++i)
	{
		if (name == forms_for_creation[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (i) 
			{
				case 0: return(new ShrubberyCreationForm(target));
				case 1: return(new RobotomyRequestForm(target));
				case 2: return(new PresidentialPardonForm(target));
				default: break;
			}
		}
	}
	std::cerr << "This type of form does not exist";
	return NULL;
}
