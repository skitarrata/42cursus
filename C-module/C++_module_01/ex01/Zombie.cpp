#include "Zombie.hpp"

void	Zombie::set_name(std::string str)
{
	static int i = 1;
	this->name = str + "_" + std::to_string(i++);
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << this->name << " is death!" << std::endl;	
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
