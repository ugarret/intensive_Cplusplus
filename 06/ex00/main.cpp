#include "Conversion.hpp"
# include <string>

int main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			Conversion conv(argv[1]);
			std::cout << conv;
		}
		else
			throw Conversion::NotConvertible();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}