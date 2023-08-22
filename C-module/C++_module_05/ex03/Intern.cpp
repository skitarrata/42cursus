#include "Intern.hpp"
#include "Form.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Form*					Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	if (formName.empty())
	{
		std::cout << "Form not found" << std::endl;
		return (NULL);
	}
	enum forms {SHRUBERRY, ROBOTOMY, PRESIDENTIAL};
	std::string		_formName[] = {std::string("shrubbery creation"), std::string("robotomy request"), std::string("presidential pardon")};
	Form*	resultForm = nullptr;
	int		i = 0;

	while (i < 3)
	{
		if (formName  == _formName[i])
			break ;
		i++;
	}

	switch (i)
	{
		case SHRUBERRY:
			resultForm = new ShrubberyCreationForm(formTarget);
			break;
		case ROBOTOMY:
			resultForm = new RobotomyRequestForm(formTarget);
			break;
		case PRESIDENTIAL:
			resultForm = new PresidentialPardonForm(formTarget);
			break;
		default:
			break;
	}
	if (resultForm != nullptr)
		std::cout << "Intern creates " << formName << std::endl;
	return resultForm;
}
