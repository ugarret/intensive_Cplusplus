#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void test(Bureaucrat bur)
{
	ShrubberyCreationForm shrubbery("home");
    bur.executeForm(shrubbery);
	bur.signForm(shrubbery);
	bur.executeForm(shrubbery);
	std::cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << std::endl;
	RobotomyRequestForm robotomy("something");
	bur.signForm(robotomy);
	bur.executeForm(robotomy);
	std::cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << std::endl;
	PresidentialPardonForm presidential("somebody");
	bur.signForm(presidential);
	bur.executeForm(presidential);
	std::cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << std::endl;
}

int main()
{
	Bureaucrat bureaucrat_1("bureaucrat_1", 1);
	Bureaucrat bureaucrat_2("bureaucrat_2", 46);
	Bureaucrat bureaucrat_3("bureaucrat_3", 113);

	test(bureaucrat_1);
	test(bureaucrat_2);
	test(bureaucrat_3);
}