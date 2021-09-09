#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		Form constitution("Constitution 1993", 10, 30);
		std::cout << constitution;
		Bureaucrat boris("Boris", 5);
		std::cout << boris;
		boris.signForm(constitution);
		std::cout << constitution;
		boris.signForm(constitution);
	}

    try
    {
       Form toHigh("toHigh", 0, 20);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
       Form toLow("toLow", 10, 199);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	{
		Form constitution("Constitution 1993", 1, 1);
		Bureaucrat boris("Ne Boris", 5);
		std::cout << boris;
		boris.signForm(constitution);
	}
}