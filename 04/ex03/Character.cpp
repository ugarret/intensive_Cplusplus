#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name)
{
	_name = name;
	std::cout << _name << " born" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(Character const &other)
{
	this->operator=(other);
}

Character &Character::operator=(Character const &other)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = other._inventory[i];
	return *this;
}

Character::~Character()
{
	std::cout << _name << " died" << std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}