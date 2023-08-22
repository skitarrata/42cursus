#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
//# include "ctime"
# include <cstdlib>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(const std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		const std::string	getTarget() const;
		void				execute( const Bureaucrat &executor ) const;
	private:
		const std::string target;
};

# endif