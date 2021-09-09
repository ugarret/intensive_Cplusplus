#include "Weapon.hpp"

static std::string random_weapon(unsigned time)
{
	srand(time + rand());
	std::string name_list[3] = {"ax", "pistol", "knife"};
	return (name_list[rand() % 3]);
}

Weapon::Weapon(std::string type)
{
	if (type == "")
		setType(random_weapon(time(NULL)));
	else
		setType(type);
	std::cout << "Hephaestus forged and sent down to earth " << RED << _type << NORM << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Lightning struck " << RED << _type << NORM << ", it turned into a useless piece of metal" << std::endl;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

std::string const &Weapon::getType()
{
	return (_type);
}