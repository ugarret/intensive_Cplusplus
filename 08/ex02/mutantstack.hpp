#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack(MutantStack const &other)
		{
			*this->operator=(other);
		}
		MutantStack &operator=(MutantStack const &other)
		{
			std::stack<T>::operator=(other);
			return (*this);
		};
		virtual ~MutantStack(void){};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return(std::stack<T>::c.begin());
		};
		iterator end()
		{
			return(std::stack<T>::c.end());
		};
};

#endif
