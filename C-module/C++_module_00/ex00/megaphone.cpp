#include <iostream>
#include <string>

int	main (int argc, char *argv[])
{
	int i;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < argc; i++)
		{
			std::string	str(argv[i]);
			for (j = 0; j < str.length(); j++)
			{
				if (str[j] >= 'a' && str[j] <= 'z')
					str[j] -= 32;
				std::cout << str[j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}