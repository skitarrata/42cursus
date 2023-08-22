#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class						ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scav);
		ScavTrap&			operator=(const ScavTrap& scav);
		~ScavTrap();

		void				attack(const std::string& target);
		void				guardGate();
};

#endif