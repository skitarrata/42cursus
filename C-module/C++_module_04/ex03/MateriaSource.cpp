#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(), _knowMat(new AMateria*[MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++)
		_knowMat[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ms) : _knowMat(new AMateria*[MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++)
		if (ms._knowMat[i])
			_knowMat[i] = ms._knowMat[i];
		else
			_knowMat[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAT_SIZE; i++)
		if (_knowMat[i])
			delete _knowMat[i];
	delete [] _knowMat;
}

void		MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;

	for (; i < MAT_SIZE && _knowMat[i]; i++)
		;

	if (i == MAT_SIZE)
		return ;

	_knowMat[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAT_SIZE; i++)
		if (_knowMat[i]->getType() == type)
			return (_knowMat[i]->clone());

	return NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	if (this != &ms) 
	{
		for (size_t i = 0; i < MAT_SIZE; i++)
			if (_knowMat[i])
				delete _knowMat[i];
		for (size_t i = 0; i < MAT_SIZE; i++)
			if (ms._knowMat[i])
				_knowMat[i] = ms._knowMat[i];
			else
				_knowMat[i] = NULL;
	}
	return *this;
}