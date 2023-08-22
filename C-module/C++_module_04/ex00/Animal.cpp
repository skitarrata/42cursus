#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor" << std::endl;
	setType("indefinited");
}

Animal::Animal(const Animal& ani)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = ani;
}

Animal&				Animal::operator=(const Animal& ani)
{
	std::cout << "Animal copy operator" << std::endl;
	if (this != &ani)
		this->type = ani.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string			Animal::getType() const
{
	return this->type;
}

void				Animal::makeSound() const
{
	std::cout << "??????" << std::endl;
}

void				Animal::setType(std::string name)
{
	this->type = name;
}