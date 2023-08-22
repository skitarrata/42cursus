#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { }

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade) 
{
	try
	{
		if (grade < MIN)
			throw GradeTooHighException();
		else if (grade > MAX)
			throw GradeTooLowException();
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
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
	try
	{
		if (grade < MIN)
			throw GradeTooHighException();
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;;
	}
}

void					Bureaucrat::DecrementGrade()
{
	grade++;
	try
	{
		if (grade > MAX)
			throw GradeTooLowException();
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;;
	}
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