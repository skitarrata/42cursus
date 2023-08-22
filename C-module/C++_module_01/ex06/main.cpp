#include "Karen.hpp"

int main(int argc, char *argv[])
{
	int 			mod = -1;
	karen 			k;
	std::string		vet[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (1);
	for (int i = 0; i < 4; i++)
		if (vet[i] == argv[1])
			mod = i;
	
	switch (mod)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			k.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			k.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			k.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			k.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}