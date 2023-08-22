#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main() 
{
	std::cout << "*------------------- Creating a robotomy request form -------------------*" << std::endl;
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf == NULL)
	{
		std::cout << "request failed" << std::endl;
		return 0;
	}
	Bureaucrat b("haha", 5);
	rrf->beSigned(b);
	rrf->execute(b);
	std::cout << std::endl;
	delete rrf;

	std::cout << "*------------------- Creating a shrubbery creation form -------------------*" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Beaaaarish");
	if (rrf == NULL)
	{
		std::cout << "request failed" << std::endl;
		return 0;
	}
	rrf->beSigned(b);
	rrf->execute(b);
	delete rrf;

	return 0;
}