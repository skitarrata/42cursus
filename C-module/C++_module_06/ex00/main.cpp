#include "Convert.hpp"

int			ftError()
{
	std::cout << "Bad Parameter" << std::endl;
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (ftError());

	Convert	conv(argv[1]);

	if (conv.err)
		return (ftError());
	std::cout << conv;

	return 0;
}