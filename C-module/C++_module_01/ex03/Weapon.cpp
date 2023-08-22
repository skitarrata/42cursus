#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	setType(str);
}

const std::string	&Weapon::getType() const
{
	return this->type;
}

void				Weapon::setType(std::string str)
{
	this->type = str;
}
