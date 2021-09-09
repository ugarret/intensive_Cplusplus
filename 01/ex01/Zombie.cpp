#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	if (name != "")
	{
		_name = name;
		std::cout << _name << " rose from the dead and is very hungry" << std::endl;
	}
	else
		std::cout << "Another warrior of the horde has risen from the dead" << std::endl;
}

void Zombie::to_each_zombie_by_name(std::string name)
{
	_name = name;
}

void Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " says: \"Oh no, my flesh is completely rotted\"" << std::endl;
}