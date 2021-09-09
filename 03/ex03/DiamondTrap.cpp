#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	_name = name;
	_hitpoint = FragTrap::_hitpoint;
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
	_max_hp = _hitpoint;
	std::cout << "DiamondTrap " << GREEN << _name << NORM << " emerged from sea foam" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << GREEN << _name << NORM << " disappeared over the horizon" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My first name is " << GREEN << _name << NORM << " and my second name is ";
	std::cout << BLUE << ClapTrap::_name << NORM << std::endl;
}