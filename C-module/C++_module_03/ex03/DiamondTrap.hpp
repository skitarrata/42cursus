#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class						DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string			_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string str);
		DiamondTrap(const DiamondTrap& dm);
		DiamondTrap&		operator=(const DiamondTrap& dm);
		~DiamondTrap();

		using				ScavTrap::attack;
		void				whoAmI();
};

#endif