#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <string>

class				Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		void 	announce(void);
		void	set_name(std::string str);
		~Zombie();
};

#endif