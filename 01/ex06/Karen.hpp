#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class	Karen
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Karen::*grumble[4])(void);

	public:
		Karen();
		~Karen();
		void complain(std::string level);
		void karenFilter(std::string level);
};

enum	Grumble
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

#endif