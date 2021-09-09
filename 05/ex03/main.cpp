#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat_1("bureaucrat_1", 1);
	Intern someRandomIntern;
	Form *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
	bureaucrat_1.signForm(*shrubbery);
	bureaucrat_1.executeForm(*shrubbery);
	delete shrubbery;
	shrubbery = someRandomIntern.makeForm("home", "home");
	delete shrubbery;
}