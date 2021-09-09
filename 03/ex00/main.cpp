#include "ClapTrap.hpp"

int main()
{
	ClapTrap Bob("Bob");
	Bob.attack("unfamiliar sexist");
	Bob.takeDamage(9);
	Bob.beRepaired(8);
	Bob.beRepaired(1);
	Bob.beRepaired(1);
	for (int i = 0; i < 10; ++i)
		Bob.attack("unfamiliar sexist");
	Bob.takeDamage(10);
	Bob.takeDamage(1);
	Bob.beRepaired(1);
}