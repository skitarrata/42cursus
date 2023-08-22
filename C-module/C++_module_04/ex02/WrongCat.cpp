#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor" << std::endl;
	setType("comune");
}

WrongCat::WrongCat(const WrongCat& wc)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = wc;
}

WrongCat&				WrongCat::operator=(const WrongCat& wc)
{
	std::cout << "WrongCat copy operator" << std::endl;
	if (this != &wc)
		this->type = wc.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void				WrongCat::makeSound() const
{
	std::cout << "wrong miao!" << std::endl;
}