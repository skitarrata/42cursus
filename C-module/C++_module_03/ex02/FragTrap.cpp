#include "FragTrap.hpp"

#define HIT 100
#define EP 100
#define DAM 30

FragTrap::FragTrap() : ClapTrap()
{ 
	std::cout << "new default constructor" << std::endl;
	hit_points = HIT;
	E_points = EP;
	dam = DAM;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "new constructor with name" << std::endl;
	hit_points = HIT;
	E_points = EP;
	dam = DAM;
}

FragTrap::FragTrap(const FragTrap& frag) : ClapTrap(frag) {std::cout << "new copy constructor" << std::endl;}
FragTrap::~FragTrap() { std::cout << "FragTrap Default destructor" << std::endl; }

FragTrap&			FragTrap::operator=(const FragTrap& frag)
{
	if (this != &frag)
	{
		name = frag.name;
		hit_points = frag.hit_points;
		E_points = frag.E_points;
		dam = frag.dam;
	}
	std::cout << "new copy operator" << std::endl;
	return *this;
}

void				FragTrap::highFiveGuys(void)
{
	std::cout << "Give me high five!!" << std::endl;
}