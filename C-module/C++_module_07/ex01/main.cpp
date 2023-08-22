#include "iter.hpp"

int main()
{
	char		c[] = "peppeniello";
	int			n[] = {1, 2, 3, 4, 5, 6};
	std::string	s[] = {"piccolo", "bimbo", "nato"};

	std::cout << "Test:\t Char" << std::endl;
	::iter(c, 11, printable);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test:\t Int" << std::endl;
	::iter(n, 6, printable);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test:\t String" << std::endl;
	::iter(s, 3, printable);
	std::cout << std::endl;
	std::cout << std::endl;
}