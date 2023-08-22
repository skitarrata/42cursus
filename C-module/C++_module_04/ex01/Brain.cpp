#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& br)
{
	std::cout << "Brain copy constructor" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = br.ideas[i];
}

Brain&				Brain::operator=(const Brain& br)
{
	std::cout << "Brain copy operator" << std::endl;
	if (this != &br)
		for (size_t i = 0; i < 100; i++)
			ideas[i] = br.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}