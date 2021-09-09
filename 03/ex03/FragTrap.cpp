#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitpoint = 100;
	_energy_point = 100;
	_attack_damage = 30;
	_max_hp = _hitpoint;
	std::cout << GREEN << "FragTrap " << _name << NORM << " born in the mouth of a volcano" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN << "FragTrap " << _name << NORM << " melted in the lava that gave birth to it" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap " << _name << NORM << ": \"High Five, Guys!\" and gave five"<< std::endl;
}
