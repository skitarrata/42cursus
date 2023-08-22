#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	std::cout << "ultimate default constructor" << std::endl;
	hit_points = FragTrap::hit_points;
	E_points = ScavTrap::E_points;
	dam = FragTrap::dam;
}

DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_name"), FragTrap(str), ScavTrap(str), _name(str)
{
	std::cout << "ultimate constructor with name" << std::endl;
	hit_points = FragTrap::hit_points;
	E_points = ScavTrap::E_points;
	dam = FragTrap::dam;
}

DiamondTrap::DiamondTrap(const DiamondTrap& dm) : ClapTrap(dm), FragTrap(dm), ScavTrap(dm), _name(dm._name)
{
	std::cout << "ultimate copy constructor" << std::endl;
}

DiamondTrap&		DiamondTrap::operator=(const DiamondTrap& dm)
{
	if (this != &dm)
	{
		name = dm.name;
		_name = dm._name;
		hit_points = dm.hit_points;
		E_points = dm.E_points;
		dam = dm.dam;	
	}
	std::cout << "ultimate copy operator" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Default destructor" << std::endl;
}

void				DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << _name << " my ClapTrap name is: " << ClapTrap::name << std::endl;
}