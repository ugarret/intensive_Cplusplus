#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class No_such_number: public std::exception
{
	virtual const char* what() const throw()
	{
		return ("No such number");
	}
};

template<typename T>
unsigned int easyfind(T &container, int needle)
{
	typename T::iterator position = std::find(container.begin(), container.end(), needle);
	if (position == container.end())
		throw No_such_number();
	return (*position);
}

#endif