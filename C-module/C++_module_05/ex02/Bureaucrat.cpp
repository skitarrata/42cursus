#include "Form.hpp"

Bureaucrat::Bureaucrat() { }

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade) 
{
		if (grade < MIN)
			throw GradeTooHighException();
		else if (grade > MAX)
			throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& br) : name(br.name), grade(br.grade)
{
	*this = br;
}

Bureaucrat&				Bureaucrat::operator=(const Bureaucrat& br)
{
	if (this != &br)
		this->grade = br.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

std::string				Bureaucrat::getName() const { return name; }

int						Bureaucrat::getGrade() const { return grade; }

void					Bureaucrat::IncrementGrade()
{
	grade--;
	if (grade < MIN)
		throw GradeTooHighException();
}

void					Bureaucrat::DecrementGrade()
{
	grade++;
	if (grade > MAX)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: grade too Low";
}

std::ostream&		operator<<(std::ostream& out, const Bureaucrat& br)
{
	out << br.getName() << ", bureaucrat grade " << br.getGrade() << "." << std::endl;
	return out;
}

void					Bureaucrat::signForm(const Form& fr)
{
	if (fr.getSign())
		std::cout << name << " signs " << fr << std::endl;
	else
		std::cout << "bureaucrat " << name << " cannot sign " << fr << " because it is not eligible." << std::endl;
}

void				Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}