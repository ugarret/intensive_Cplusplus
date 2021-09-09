#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << BLUE << _name << NORM << " has trained for hundreds of years and is ready to fight" << std::endl;
	std::cout << BLUE << _name << NORM << " picked up " << RED << _weapon.getType() << NORM << " and went on the warpath" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << BLUE << _name << NORM << " went under the sad music in the sunset" << std::endl;
}

void HumanA::attack()
{
	std::cout << BLUE << _name << NORM << " attacks with his " << RED << _weapon.getType() << NORM << std::endl;
}