#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

void identify(Base* p)
{
	std::cout << "id_ptr:";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void identify(Base &p)
{
	std::cout << "id_ref:";
	try
	{
		Base &cast_ref = dynamic_cast<A &>(p);
		std::cout << "A";
		cast_ref.~Base();
	}
	catch (std::exception &ex){}
	try
	{
		Base &cast_ref = dynamic_cast<B &>(p);
		std::cout << "B";
		cast_ref.~Base();
	}
	catch (std::exception &ex){}
	try
	{
		Base &cast_ref = dynamic_cast<C &>(p);
		std::cout << "C";
		cast_ref.~Base();
	}
	catch (std::exception &ex){}
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		Base *ptr = generate();
		std::cout << "Test " << i << ": ";
		identify(ptr);
		std::cout << ", ";
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}

	return (0);
}