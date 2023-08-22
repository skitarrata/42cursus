#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class						ClapTrap
{
	private:
		std::string			name;
		int					hit_points;
		int					E_points;
		int					dam;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& clap);
		ClapTrap&			operator=(const ClapTrap& clap);
		~ClapTrap();

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
};

#endif