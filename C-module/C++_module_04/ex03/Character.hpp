#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define INV_SIZE 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria**	_inventory;
	public:
		Character(std::string name);
		Character(const Character& ch);
		~Character();

		Character& operator=(const Character& ch);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif