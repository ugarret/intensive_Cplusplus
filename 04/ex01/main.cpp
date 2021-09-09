#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animal[4];
	for (int i = 0; i < 2; ++i)
		animal[i] = new Cat();
	for (int j = 2; j < 4; ++j)
		animal[j] = new Dog();
	std::cout << "\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n\n";
	for (int k = 0; k < 4; ++k)
		animal[k]->makeSound();
	std::cout << "\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n\n";
	*animal[0] = *animal[1];
	for (int r = 0; r < 4; ++r)
		delete animal[r];
	std::cout << "\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n\n";
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;//should not create a leak
	delete i;
	while(1);
	return 0;
}