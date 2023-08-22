#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	setType("comune");
}

Cat::Cat(const Cat& c)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = c;
}

Cat&				Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &c)
		this->type = c.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void				Cat::makeSound() const
{
	std::cout << "miao! miao!" << std::endl;
}