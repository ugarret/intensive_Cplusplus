#include "Karen.hpp"

Karen::Karen()
{
	std::cout << "Grumpy Karen came to your diner" << std::endl;
	grumble[0] = &Karen::debug;
	grumble[1] = &Karen::info;
	grumble[2] = &Karen::warning;
	grumble[3] = &Karen::error;
}

Karen::~Karen()
{
	std::cout << "Grumpy Karen left your diner" << std::endl;
}

void Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t ";
	std::cout << "put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming ";
	std::cout << "here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	std::string level_of_discontent[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i <= 3; ++i)
		if (level == level_of_discontent[i])
		{
			switch (i)
			{
				case DEBUG:
				std::cout << "[ DEBUG ]\n";
				(this->*grumble[DEBUG])();
				std::cout << "\n";
				case INFO:
				std::cout << "[ INFO ]\n";
				(this->*grumble[INFO])();
				std::cout << "\n";
				case WARNING:
				std::cout << "[ WARNING ]\n";
				(this->*grumble[WARNING])();
				std::cout << "\n";
				case ERROR:
				std::cout << "[ ERROR ]\n";
				(this->*grumble[ERROR])();
				std::cout << "\n";
				return ;
			}
		}
	std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
}