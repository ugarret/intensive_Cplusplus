#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class	Zombie
{
	public:
		Zombie(std::string name = "");
		~Zombie();
		void announce(void);
		void to_each_zombie_by_name(std::string name);

	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif