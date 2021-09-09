#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "The emergence of the brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	this->operator=(other);
}

Brain &Brain::operator=(const Brain &other)
{
	this->_ideas = new 
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Complete degradation of brain" << std::endl;
}
