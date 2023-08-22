#include "FragTrap.hpp"

int main(void)
{
	FragTrap	a;
	FragTrap	b("peppa");
	FragTrap	c(b);
	FragTrap	d;

	d = c;

	a.attack("gigio");
	a.takeDamage(6);
	a.beRepaired(3);
	a.highFiveGuys();
	std::cout << std::endl;
	b.attack("ciccio");
	b.takeDamage(8);
	b.beRepaired(6);
	b.highFiveGuys();
	std::cout << std::endl;
	c.attack("lillo");
	c.takeDamage(4);
	c.beRepaired(2);
	c.highFiveGuys();
	std::cout << std::endl;
	d.attack("nello");
	d.takeDamage(7);
	d.beRepaired(9);
	d.highFiveGuys();
	std::cout << std::endl;
	return (0);
}