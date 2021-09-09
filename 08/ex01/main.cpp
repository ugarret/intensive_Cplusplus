#include <iostream>
#include "Span.hpp"
#include <ctime>

void mini_test_from_subject()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "longest span = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void big_test()
{
	try
	{
		srand(time(NULL));

		int tmp;
		Span sp = Span(10000);
		std::vector<int> vec;
		for (int i = 0; i < 10000; ++i)
		{
			tmp = (rand() % 1000) - 42;
			vec.push_back(tmp);
			std::cout << tmp << " ";
		}
		sp.addArrNumber(vec.begin(), vec.end());
		std::cout << std::endl;
		std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "longest span = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	// mini_test_from_subject();
	big_test();
}