#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class 								ICharacter;

class								AMateria
{
	protected:
		std::string					type;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& ama);
		virtual ~AMateria();
		virtual AMateria&					operator=(const AMateria& ama);
		
		std::string const &			getType() const;
		virtual AMateria*			clone() const = 0;
		virtual void				use(ICharacter& target);
};

#endif