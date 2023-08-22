#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), W2(NULL) {}

void		HumanB::setWeapon(Weapon &weapon)
{
	this->W2 = &weapon;
}

void	HumanB::attack()
{
	if (W2)
		std::cout << this->name << " attacks with their " << W2->getType() << std::endl;
}