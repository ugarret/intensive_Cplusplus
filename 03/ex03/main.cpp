#include "DiamondTrap.hpp"

int main()
{
	{
		ScavTrap Bob("Bob");
		Bob.attack("unfamiliar sexist");
		Bob.takeDamage(9);
		Bob.beRepaired(8);
		Bob.takeDamage(1);
		Bob.guardGate();
		Bob.beRepaired(1);
	}
	std::cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n" << std::endl;
	{
		FragTrap Ann("Ann");
		Ann.attack("unfamiliar sexist");
		Ann.takeDamage(9);
		Ann.beRepaired(8);
		Ann.takeDamage(1);
		Ann.highFivesGuys();
		Ann.beRepaired(1);
	}
	std::cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n" << std::endl;
	{
		ClapTrap Liza("Liza");
		Liza.attack("unfamiliar sexist");
	}
	std::cout << "\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n" << std::endl;
	{
		DiamondTrap Kolyan("Kolyan");
		Kolyan.attack("unfamiliar sexist");
		Kolyan.takeDamage(9);
		Kolyan.beRepaired(8);
		Kolyan.highFivesGuys();
		Kolyan.guardGate();
		Kolyan.whoAmI();
	}
}