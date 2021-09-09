#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):	_name(name), _hitpoint(10),
										_energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << BLUE << _name << NORM << " was born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->operator=(other);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energy_point = other._energy_point;
	this->_attack_damage = other._attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << BLUE << _name << NORM << " was wiped off the face of the earth" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (_hitpoint <= 0)
	{
		std::cout << "Broken ClapTraps don't attack anybody" << std::endl;
		return ;
	}
	if (_energy_point > 0)
	{
		_energy_point--;
		std::cout << "ClapTrap " << BLUE << _name << NORM << " attacks " << BLUE << target << NORM << ", causing ";
		std::cout << RED << _attack_damage << NORM << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << BLUE << _name << NORM << " has spent all his strength and can no longer attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoint > 0)
	{
		if ((_hitpoint -= amount) > 0)
		{
			std::cout << "ClapTrap " << BLUE << _name << NORM << " takes " << RED << amount << NORM; 
			std::cout << " damage, but bravely continues to fight" << std::endl;
		}
		else
			std::cout << "ClapTrap " << BLUE << _name << NORM << " takes damage incompatible with life" << std::endl;
	}
	else
		std::cout << "* The sounds of impacts on the destroyed ClapTrap *" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoint == 10)
	{
		std::cout << "ClapTrap " << BLUE << _name << NORM << " has maximum HP" << std::endl;
		return ;
	}
	if (_hitpoint > 0)
	{
		if ((_hitpoint += amount) >= 10)
		{
			_hitpoint = 10;
			std::cout << "ClapTrap " << BLUE << _name << NORM << " restored maximum HP" << std::endl;
		}
		else
			std::cout << "ClapTrap " << BLUE << _name << NORM << " restored " << GREEN << amount << NORM << " HP" << std::endl;
	}
	else
		std::cout << "* Futile attempts to restore the destroyed ClapTrap *" << std::endl;;
}
