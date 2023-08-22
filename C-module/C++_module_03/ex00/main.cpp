#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a;
	ClapTrap	b("peppa");
	ClapTrap	c(b);
	ClapTrap	d;

	d = c;

	a.attack("gigio");
	a.takeDamage(6);
	a.beRepaired(3);
	std::cout << std::endl;
	b.attack("ciccio");
	b.takeDamage(6);
	b.beRepaired(3);
	std::cout << std::endl;
	c.attack("lillo");
	c.takeDamage(6);
	c.beRepaired(3);
	std::cout << std::endl;
	d.attack("nello");
	d.takeDamage(6);
	d.beRepaired(3);
	std::cout << std::endl;
	return (0);
}