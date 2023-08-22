#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), W1(weapon) {}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << W1.getType() << std::endl;
}
