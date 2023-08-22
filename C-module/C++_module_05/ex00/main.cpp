#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("peppa", 15);
	std::cout << b1 << std::endl;

	for(int i = 0; i < 14; ++i)
		b1.IncrementGrade();

	std::cout << b1 << std::endl;

	b1.IncrementGrade();

	std::cout << b1 << std::endl;

	for(int i = 0; i < 151; ++i)
		b1.DecrementGrade();

	std::cout << b1 << std::endl;


	Bureaucrat b2("saverio", 0);
	return 0;
}