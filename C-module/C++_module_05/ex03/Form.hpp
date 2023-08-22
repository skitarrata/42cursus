#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class								Form
{
	private:
		const std::string			name;
		bool						sign;
		const int					gradeS;
		const int					gradeE;
	public:
		Form(const std::string _name, int _gradeE, int _gradeS);
		Form(const Form& fr);
		Form&						operator=(const Form& fr);
		virtual ~Form();

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

		class FormCannotBeExecuted : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string					getName() const;
		bool						getSign() const;
		int							getGradeSign() const;
		int							getGradeExecute() const;
		void						beSigned(const Bureaucrat& br);
		virtual void				execute(Bureaucrat const & executor) const = 0;
		void						checkExecutable(const Bureaucrat &executor) const;
};

std::ostream&						operator<<(std::ostream& out, const Form& fr);

#endif