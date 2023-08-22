#include "ScavTrap.hpp"

#define HIT 100
#define EP 50
#define DAM 20

ScavTrap::ScavTrap() : ClapTrap()
{ 
	std::cout << "new default constructor" << std::endl;
	hit_points = HIT;
	E_points = EP;
	dam = DAM;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "new constructor with name" << std::endl;
	hit_points = HIT;
	E_points = EP;
	dam = DAM;
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav) {std::cout << "new copy constructor" << std::endl;}
ScavTrap::~ScavTrap() { std::cout << "ScavTrap Default destructor" << std::endl; }

ScavTrap&			ScavTrap::operator=(const ScavTrap& scav)
{
	if (this != &scav)
	{
		name = scav.name;
		hit_points = scav.hit_points;
		E_points = scav.E_points;
		dam = scav.dam;
	}
	std::cout << "new copy operator" << std::endl;
	return *this;
}

void				ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name << " attacks " << target <<", causing " << dam << " points of damage!"	<< std::endl;
}

void				ScavTrap::guardGate()
{
	std::cout << "Gate keeper mode!!" << std::endl;
}