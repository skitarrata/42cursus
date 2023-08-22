#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor" << std::endl;
	setType("indefinited");
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = wa;
}

WrongAnimal&				WrongAnimal::operator=(const WrongAnimal& wa)
{
	std::cout << "WrongAnimal copy operator" << std::endl;
	if (this != &wa)
		this->type = wa.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

std::string			WrongAnimal::getType() const
{
	return this->type;
}

void				WrongAnimal::makeSound() const
{
	std::cout << "??????" << std::endl;
}

void				WrongAnimal::setType(std::string name)
{
	this->type = name;
}