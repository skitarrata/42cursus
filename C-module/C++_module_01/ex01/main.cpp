#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main(void)
{
	int n = 10;
	Zombie *zom;
	zom = zombieHorde(n, "saverio");
	if (!zom)
		exit (0);
	for (int i = 0; i < n; i++)
		zom[i].announce();
	delete[] zom;
	return (0);
}
