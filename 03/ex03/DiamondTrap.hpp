#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		void attack(std::string const &target);
		void whoAmI();
	private:
		std::string _name;
};

#endif