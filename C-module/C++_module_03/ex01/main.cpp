#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	a;
	ScavTrap	b("peppa");
	ScavTrap	c(b);
	ScavTrap	d;

	d = b;

	a.attack("gigio");
	a.takeDamage(6);
	a.beRepaired(3);
	a.guardGate();
	std::cout << std::endl;
	b.attack("ciccio");
	b.takeDamage(6);
	b.beRepaired(3);
	b.guardGate();
	std::cout << std::endl;
	c.attack("lillo");
	c.takeDamage(6);
	c.beRepaired(3);
	c.guardGate();
	std::cout << std::endl;
	d.attack("nello");
	d.takeDamage(6);
	d.beRepaired(3);
	d.guardGate();
	std::cout << std::endl;
	return (0);
}