#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, int length, void (*function)(T const &))
{
	for (int i = 0; i < length; ++i)
		function(array[i]);
}

template<typename T>
void print_element(T const &element)
{
	std::cout << element << " ";
}

template<typename T>
void cast_to_int_and_print(T const &element)
{
	std::cout << static_cast<int>(element) << " ";
}

#endif