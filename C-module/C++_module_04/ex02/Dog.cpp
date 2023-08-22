#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	setType("meticcio");
	brd = new Brain();
}

Dog::Dog(const Dog& d)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->type = d.type;
	brd = new Brain(*d.brd);
}

Dog&				Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &d)
	{
		this->type = d.type;
		brd = new Brain(*d.brd);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete brd;
}

void				Dog::makeSound() const
{
	std::cout << "bau! bau!" << std::endl;
}

Brain*				Dog::getBrain() const
{
	return (brd);
}
