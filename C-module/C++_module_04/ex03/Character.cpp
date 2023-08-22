#include "Character.hpp"

Character::Character(std::string name) : ICharacter(), _name(name), _inventory(new AMateria*[INV_SIZE])
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& ch)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (ch._inventory[i])
			_inventory[i] = ch._inventory[i]->clone();
}

Character::~Character() 
{
	for (int i = 0; i < INV_SIZE; i++)
		if (_inventory[i])
			delete _inventory[i];
	delete [] _inventory;
}

Character& Character::operator=(const Character& ch)
{
	if (this != &ch)
	{
		for (int i = 0; i < INV_SIZE; i++)
			if (_inventory[i])
				delete _inventory[i];
		for (int i = 0; i < INV_SIZE; i++)
			if (ch._inventory[i])
				_inventory[i] = ch._inventory[i]->clone();
			else
				_inventory[i] = NULL;
	}
	return (*this);
}

std::string const & Character::getName() const { return (_name); }

void	Character::equip(AMateria* m)
{
	int	i = 0;

	for (; i < INV_SIZE && _inventory[i]; i++)
		;

	if (i == INV_SIZE)
		return ;

	_inventory[i] = m;
}

void	Character::unequip(int idx) { _inventory[idx] = NULL; }

void	Character::use(int idx, ICharacter& target) { _inventory[idx]->use(target); }