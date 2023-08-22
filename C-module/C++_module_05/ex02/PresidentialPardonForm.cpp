# include "PresidentialPardonForm.hpp"

# define NAME "PresidentialPardonForm"
# define REQ_SIGN 25
# define REQ_EXEC 5

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : Form(NAME, REQ_EXEC, REQ_EXEC), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(NAME, REQ_EXEC, REQ_EXEC), target(getTarget())
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() { }

const std::string	PresidentialPardonForm::getTarget() const { return (target); }

void					PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	checkExecutable(executor);
	std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	std::cout << "Can't copy anything" << std::endl;
	other.getTarget();

	return *this;
}