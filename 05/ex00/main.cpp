#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bureaucrat("Bur", 2);
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("Bur", 149);
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat toHigh("toHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    
	try
	{
		Bureaucrat toLow("toLow", 420);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}