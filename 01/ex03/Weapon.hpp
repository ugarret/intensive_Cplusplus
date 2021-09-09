#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
#define NORM	"\033[0m"
#define BLUE	"\033[1;34m"
#define RED		"\033[1;31m"


class	Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type = "");
		~Weapon();
		void setType(std::string type);
		std::string const &getType();
};

#endif