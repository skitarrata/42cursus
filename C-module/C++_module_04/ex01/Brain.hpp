#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class						Brain
{
	public:
		std::string			ideas[100];
		Brain();
		Brain(const Brain& br);
		~Brain();
		Brain&				operator=(const Brain& br);
};

#endif