#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	setType("comune");
	brc = new Brain();
}

Cat::Cat(const Cat& c)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->type = c.type;
	brc = new Brain(*c.brc);
}

Cat&				Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &c)
	{
		this->type = c.type;
		brc = new Brain(*c.brc);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete brc;
}

void				Cat::makeSound() const
{
	std::cout << "miao! miao!" << std::endl;
}

Brain*				Cat::getBrain() const
{
	return (brc);
}