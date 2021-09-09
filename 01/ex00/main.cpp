#include "Zombie.hpp"

static std::string random_name()
{
	std::string name_list[10] = {"Shaun", "Liz", "Noel", "Philip", "Ed",
								"Pete", "Barbara", "David", "Dianne", "Simon"};
	return (name_list[rand() % 10]);
}

int main()
{
	srand(time(NULL));//устанавливает передаваемое пользователем значение в качестве стартового. srand() следует вызывать только один раз — в начале программы
	Zombie *ptr_zombie = NULL;

	ptr_zombie = newZombie(random_name());
	randomChump(random_name());
	delete ptr_zombie;
	return 0;
}
