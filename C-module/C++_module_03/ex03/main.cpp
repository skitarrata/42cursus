#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	a;
	DiamondTrap	b("peppa");
	DiamondTrap	c(b);
	DiamondTrap	d;

	d = a;

	a.attack("gigio");
	a.takeDamage(6);
	a.beRepaired(3);
	a.whoAmI();
	std::cout << std::endl;
	b.attack("ciccio");
	b.takeDamage(8);
	b.beRepaired(6);
	b.whoAmI();
	std::cout << std::endl;
	c.attack("lillo");
	c.takeDamage(4);
	c.beRepaired(2);
	c.whoAmI();
	std::cout << std::endl;
	d.attack("nello");
	d.takeDamage(7);
	d.beRepaired(9);
	d.whoAmI();
	std::cout << std::endl;
	return (0);
}