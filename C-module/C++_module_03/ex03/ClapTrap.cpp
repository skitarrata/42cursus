#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :name("default"), hit_points(10), E_points(10), dam(0) { std::cout << "Default constructor" << std::endl; }
ClapTrap::ClapTrap(std::string _name) : name(_name), hit_points(10), E_points(10), dam(0) { std::cout << "constructor with name" << std::endl; }
ClapTrap::~ClapTrap() { std::cout << "Default destructor" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& clap) 
{
	std::cout << "copy constructor" << std::endl;
	*this = clap;
}

ClapTrap&			ClapTrap::operator=(const ClapTrap& clap)
{
	std::cout << "copy operator" << std::endl;
	if (this != &clap)
	{
		this->name = clap.name;
		this->dam = clap.dam;
		this->E_points = clap.E_points;
		this->hit_points = clap.hit_points;
	}
	return (*this);
}

void				ClapTrap::attack(const std::string& target) 
{
	std::cout << "ClapTrap " << name << " attacks " << target <<", causing " << dam << " points of damage!"	<< std::endl;
}

void				ClapTrap::takeDamage(unsigned int amount) 
{
	if (E_points)
	{
		hit_points -= amount;
		E_points--;
	}
	else
	{
		std::cout << "you have no Energy points" << std::endl;
		return ;
	}
	if (hit_points <= 0)
		hit_points = 0;
	std::cout << name << " takes damages for " << amount <<" hit points, you have " << hit_points << " hit points left" << std::endl;
}

void				ClapTrap::beRepaired(unsigned int amount) 
{
	if (E_points)
	{
		hit_points += amount;
		E_points--;
	}
	else
	{
		std::cout << "you have no Energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "<< name << " got " << amount <<" of sweet life juice!, you have " << hit_points << " hit points left" << std::endl;
}
