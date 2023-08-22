#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Form			*form = NULL;
	Bureaucrat		bob("bob", 130);
	Bureaucrat		phil("phil", 40);
	Bureaucrat		luc("luc", 1);

	std::cout << "-----ShrubberyCreationForm-----" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("28C");
		form->beSigned(bob);
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----RobotomyRequestForm-----" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28C");
		form->beSigned(phil);
		phil.signForm(*form);
		phil.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----PresidentialPardonForm-----" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28C");
		form->beSigned(luc);
		luc.signForm(*form);
		luc.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}