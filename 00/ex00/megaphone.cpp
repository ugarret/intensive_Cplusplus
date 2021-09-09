#include <iostream>

int main(int argc, char **argv)
{
	unsigned	i, j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (j = 1; j < argc; j++)
		{
			std::string str(argv[j]);
			for (i = 0; i < str.length(); i++)
				str[i] = toupper(str[i]);
			std::cout << str;
		}
	std::cout << std::endl;
	return (0);
}
