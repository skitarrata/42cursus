#include "Form.hpp"

Form::Form(const std::string _name, int _gradeE, int _gradeS) : name(_name), sign(false), gradeS(_gradeS), gradeE(_gradeE)
{
	if (gradeE < MIN || gradeS < MIN)
		throw Form::GradeTooHighException();
	else if (gradeE > MAX || gradeS > MAX)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& fr) :  name(fr.name), sign(fr.sign), gradeS(fr.gradeS), gradeE(fr.gradeE) { *this = fr; }

Form&						Form::operator=(const Form& fr)
{
	if(this != &fr)
		this->sign = fr.sign;
	return (*this);
}

Form::~Form() { }

void						Form::beSigned(const Bureaucrat& br)
{
	if (br.getGrade() <= gradeS)
		sign = true;
	else
	{
		sign = false;
		if (br.getGrade() > MAX)
			throw Form::GradeTooLowException();
	}
}

std::string					Form::getName() const { return name; }
bool						Form::getSign() const { return sign; }
int							Form::getGradeSign() const { return gradeS; }
int							Form::getGradeExecute() const { return gradeE; }

std::ostream&		operator<<(std::ostream& out, const Form& fr)
{
	out << fr.getName() << " Form has to be signed by a "
	<< fr.getGradeSign() << " grade and executed by a "
	<< fr.getGradeExecute() << " grade, it is "
	<< ((fr.getSign()) ? "" : "not ") << "signed";

	return out;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high: the maximum allowed value is 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low: the minimum allowed value is 150");
}

const char* Form::FormCannotBeExecuted::what() const throw()
{
	return ("Form cannot be executed");
}

void				Form::checkExecutable(const Bureaucrat &executor) const
{
	if (!sign || executor.getGrade() > gradeE)
		throw Form::FormCannotBeExecuted();
}