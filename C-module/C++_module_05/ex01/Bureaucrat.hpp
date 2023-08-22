#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MIN 1
# define MAX 150

class							Form;

class							Bureaucrat
{
	private:
		const std::string		name;
		int						grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& bu);
		Bureaucrat&				operator=(const Bureaucrat& bu);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string				getName() const;
		int						getGrade() const;
		void					IncrementGrade();
		void					DecrementGrade();
		void					signForm(const Form& fr);
};

std::ostream&					operator<<(std::ostream& out, const Bureaucrat& br);

#endif