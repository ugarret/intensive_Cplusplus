#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	std::cout << BLUE << _name << NORM << " was born unarmed" << std::endl;
	_weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << BLUE << _name << NORM << " left this world" << std::endl;
}

void HumanB::attack()
{
	if (_weapon)
		std::cout << BLUE << _name << NORM << " attacks with his " << RED << _weapon->getType() << NORM << std::endl;
	else
		std::cout << BLUE << _name << NORM << " attacks barehanded" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << BLUE << _name << NORM << " picked up " << RED << _weapon->getType() << NORM << std::endl;
}