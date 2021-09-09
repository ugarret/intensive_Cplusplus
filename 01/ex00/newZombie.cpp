#include <iostream>
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *ptr_new_zombie;
	ptr_new_zombie = new Zombie(name);
	return (ptr_new_zombie);
}