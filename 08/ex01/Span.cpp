#include "Span.hpp"

Span::Span(unsigned int N): _size(N)
{}

Span::Span(Span const &other)
{
	this->operator=(other);
}

Span &Span::operator=(Span const &other)
{
	_size = other.get_size();
	_elements.assign(other._elements.begin(), other._elements.end());
	return (*this);
}

Span::~Span()
{}

unsigned int Span::get_size() const
{
	return(_size);
}

std::vector<int> Span::get_elements() const
{
	return(_elements);
}

int Span::operator[](unsigned int index) const
{
	if (index >= this->get_size())
		throw SomethingWentWrong();
	return (this->get_elements()[index]);
}

void Span::addNumber(int n)
{
	if (this->_elements.size() >= this->get_size())
		throw SomethingWentWrong();
	_elements.push_back(n);
}

void Span::addArrNumber(std::vector<int>::iterator start, std::vector<int>::iterator finish)
{
	if (std::distance(_elements.end(), _elements.begin() + this->get_size()) < std::distance(start, finish))
		throw SomethingWentWrong();
	_elements.insert(_elements.begin() + _elements.size(), start, finish);
}

int	Span::shortestSpan()
{
	if (this->get_elements().size() < 2)
		throw SomethingWentWrong();
	std::vector<int>::iterator i = _elements.begin();
	int diff = std::abs(*(i + 1) - *i);
	int abs_iter;
	while (i + 1 != _elements.end())
	{
		abs_iter = std::abs(*(i + 1) - *i);
		diff = (diff < abs_iter ? diff : abs_iter);
		++i;
	}
	return (diff);
}

int	Span::longestSpan()
{
	if (_elements.size() < 2)
		throw SomethingWentWrong();
	std::vector<int>::iterator i = _elements.begin();
	int diff = 0;
	int abs_iter;
	while (i + 1 != _elements.end())
	{
		abs_iter = std::abs(*(i + 1) - *i);
		diff = (diff > abs_iter ? diff : abs_iter);
		++i;
	}
	return (diff);
}

const char *Span::SomethingWentWrong::what() const throw()
{
	return("Something went wrong");
}