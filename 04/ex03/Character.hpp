#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
// #include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_inventory[4];
		std::string _name;
	public:
		Character(std::string name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		~Character();
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif