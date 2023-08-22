#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie z1("saverio");
	z1.announce();

	Zombie *z2 = newZombie("felice");
	z2->announce();

	randomChump("jackie");
	delete z2;

	return (0);
}
