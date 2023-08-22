#include "Karen.hpp"

void	karen::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special\n-ketchup burger. I really do!" << std::endl;
}

void	karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t pute\nnough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\nyears whereas you started working here since last month." << std::endl;
}

void	karen::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	karen::complain(std::string level)
{
	std::string		vet[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(karen::*pfun[4])(void) = {&karen::debug, &karen::info, &karen::warning, &karen::error};
	for (int i = 0; i < 4; i++)
	{
		if (vet[i] == level)
		{
			(this->*pfun[i])();
			return;
		}
	}
}