#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << " ";
	dog->makeSound();
	std::cout << cat->getType() << " ";
	cat->makeSound(); //will output the cat sound!
	animal->makeSound();
	const WrongAnimal *wrong_a = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << wrong_cat->getType() << " ";
	wrong_cat->makeSound();
	wrong_a->makeSound();
	return 0;
}