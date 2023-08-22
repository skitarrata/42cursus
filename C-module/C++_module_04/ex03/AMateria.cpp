#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& ama) { type = ama.type; }

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) { std::cout << target.getName() << std::endl; }

AMateria& AMateria::operator=(const AMateria& ama)
{
	if (this != &ama)
		this->type = ama.type;
	return (*this);
}