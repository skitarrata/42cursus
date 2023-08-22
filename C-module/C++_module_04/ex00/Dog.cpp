#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	setType("meticcio");
}

Dog::Dog(const Dog& d)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = d;
}

Dog&				Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &d)
		this->type = d.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void				Dog::makeSound() const
{
	std::cout << "bau! bau!" << std::endl;
}
