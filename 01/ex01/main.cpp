#include "Zombie.hpp"

static std::string random_name(unsigned time)
{
	srand(time + rand());
	std::string name_list[10] = {"Shaun", "Liz", "Noel", "Philip", "Ed",
								"Pete", "Barbara", "David", "Dianne", "Simon"};
	return (name_list[rand() % 10]);
}

int main()
{
	Zombie *ptr_zombie = NULL;
	int number = 3;

	std::cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << std::endl;
	std::cout << "Attempt to create a horde of " << number << " zombies" << std::endl;
	ptr_zombie = zombieHorde(number, random_name(time(NULL)));
	delete [] ptr_zombie;
	std::cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << std::endl;
	number = -1;
	std::cout << "Attempt to create a horde of " << number << " zombies" << std::endl;
	ptr_zombie = zombieHorde(number, random_name(time(NULL)));
	delete [] ptr_zombie;
}