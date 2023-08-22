#include <iostream>
#include <string>
#include <fstream>

void	ft_error(std::string str)
{
	std::cout << str << std::endl;
	std::exit(0);
}

void	ft_readFile(std::string name, std::string &str)
{
	char			c;
	std::ifstream	f;

	f.open(name);
	if (!f)
		ft_error("error open file");
	while (f.get(c))
		str += c;
	if (!f.eof())
		ft_error("Error read");
	f.close();
}

std::string	ft_replace(std::string s1, std::string s2, std::string &str)
{
    std::size_t l = s1.length();
    std::string dst;

    std::string::size_type before_pos = 0;
    std::string::size_type pos = str.find(s1);
    while (pos != std::string::npos)
    {
        dst += str.substr(before_pos, pos - before_pos);
        dst += s2;
        before_pos = pos + l;
        pos = str.find(s1, before_pos);
    }
    dst += str.substr(before_pos);
    return dst;
}

void	ft_writeFile(std::string name, std::string &str)
{
	std::ofstream f;

	f.open(name);
    if (!f)
        ft_error("Failed to open");
    f << str;
    if (f.fail())
        ft_error("Failed to write");
	f.close();
}

int	main(int argc, char *argv[])
{
	std::string	tmp;

	if (argc != 4 || !argv[2] || !argv[3])
		ft_error("Error");

	std::string filename = argv[1];
	ft_readFile(filename, tmp);
	filename += ".replace";
	tmp = ft_replace(argv[2], argv[3], tmp);
	ft_writeFile(filename, tmp);
	return 0;
}
