#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& cur) : AMateria(cur) {}

Cure::~Cure() {}

AMateria*	Cure::clone() const { return (new Cure()); }

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure& Cure::operator=(const Cure& cur)
{
	if (this != &cur)
		type = cur.type;
	return (*this);
}