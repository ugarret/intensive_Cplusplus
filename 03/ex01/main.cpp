#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap Bob("Bob");
		Bob.attack("unfamiliar sexist");
		Bob.takeDamage(9);
		Bob.beRepaired(8);
		Bob.beRepaired(1);
		Bob.beRepaired(1);
		Bob.takeDamage(10);
		Bob.takeDamage(1);
		Bob.guardGate();
		Bob.beRepaired(1);
	}
	{
		ClapTrap Liza("Liza");
		Liza.attack("unfamiliar sexist");
	}
}