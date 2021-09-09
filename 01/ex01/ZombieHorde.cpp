#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Hordes are only positive by number" << std::endl;
		return NULL;
	}
	Zombie *horde_of_zombie = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde_of_zombie[i].to_each_zombie_by_name(name);
		horde_of_zombie[i].announce();
	}
	std::cout << "Horde of zombie ready to fight" << std::endl;
	return horde_of_zombie;
}