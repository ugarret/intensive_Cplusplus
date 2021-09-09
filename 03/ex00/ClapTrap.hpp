#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define NORM	"\033[0m"
#define BLUE	"\033[1;34m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitpoint;
		int			_energy_point;
		int			_attack_damage;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif