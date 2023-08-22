#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class				HumanA
{
	private:
		std::string	name;
		Weapon		&W1;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(){};
		void		attack();
};

#endif