#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitpoint = 100;
	_energy_point = 50;
	_attack_damage = 20;
	_max_hp = _hitpoint;
	std::cout << BLUE << "ScavTrap " << _name << NORM << " created by a great genius" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap " << _name << NORM << " left the mortal world" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (_hitpoint <= 0)
	{
		std::cout << "Broken ScavTrap don't attack anybody" << std::endl;
		return ;
	}
	if (_energy_point > 0)
	{
		_energy_point--;
		std::cout << BLUE << "ScavTrap " << _name << NORM << " attacks with sound \"BTYANNG\" " << BLUE << target << NORM << ", causing ";
		std::cout << RED << _attack_damage << NORM << " points of damage!" << std::endl;
	}
	else
		std::cout << BLUE << "ScavTrap " << _name << NORM << " has spent all his strength and can no longer attack" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << _name << NORM << " have enterred in Gate keeper mode\nHELL YEAH!" << std::endl;
}