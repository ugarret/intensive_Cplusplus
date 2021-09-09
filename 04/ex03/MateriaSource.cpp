#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource сreated" << std::endl;
	for (int i = 0; i < 4; ++i)
		_repository_of_knowledge[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	this->operator=(other);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < 4; ++i)
		this->_repository_of_knowledge[i] = other._repository_of_knowledge[i];
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_repository_of_knowledge[i])
			delete _repository_of_knowledge[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_repository_of_knowledge[i])
		{
			_repository_of_knowledge[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_repository_of_knowledge[i]->getType() == type)
			return (_repository_of_knowledge[i]);
	}
	return NULL;
}