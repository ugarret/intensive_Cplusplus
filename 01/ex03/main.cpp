#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

static std::string random_name(unsigned time)
{
	srand(time + rand());
	std::string name_list[10] = {"Shaun", "Liz", "Noel", "Philip", "Ed",
								"Pete", "Barbara", "David", "Dianne", "Simon"};
	return (name_list[rand() % 10]);
}

int main()
{
	{
		Weapon gun;
		HumanA humanA(random_name(time(NULL)), gun);
		humanA.attack();
		HumanB humanB(random_name(time(NULL)));
		humanB.attack();
		humanB.setWeapon(gun);
		humanB.attack();
	}
	std::cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}