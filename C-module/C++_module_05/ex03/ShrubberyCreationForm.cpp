#include "ShrubberyCreationForm.hpp"

# define NAME "ShrubberyCreationForm"
# define REQ_SIGN 145
# define REQ_EXEC 137

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : Form(NAME, REQ_EXEC, REQ_EXEC), target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(NAME, REQ_EXEC, REQ_EXEC), target(getTarget())
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string	ShrubberyCreationForm::getTarget() const { return (target); }

void				ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	checkExecutable(executor);

	std::string out = target + "_shruberry";
	std::ofstream	fdOut(out);

	fdOut << "                                                         .";
	fdOut << "\n                                              .         ;  ";
	fdOut << "\n                 .              .              ;%     ;;   ";
	fdOut << "\n                   ,           ,                :;%  %;   ";
	fdOut << "\n                    :         ;                   :;%;'     .,   ";
	fdOut << "\n           ,.        %;     %;            ;        %;'    ,;";
	fdOut << "\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'";
	fdOut << "\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' ";
	fdOut << "\n               ;%;      %;        ;%;        % ;%;  ,%;'";
	fdOut << "\n                `%;.     ;%;     %;'         `;%%;.%;'";
	fdOut << "\n                 `:;%.    ;%%. %@;        %; ;@%;%'";
	fdOut << "\n                    `:%;.  :;bd%;          %;@%;'";
	fdOut << "\n                      `@%:.  :;%.         ;@@%;'   ";
	fdOut << "\n                        `@%.  `;@%.      ;@@%;         ";
	fdOut << "\n                          `@%%. `@%%    ;@@%;        ";
	fdOut << "\n                            ;@%. :@%%  %@@%;       ";
	fdOut << "\n                              %@bd%%%bd%%:;     ";
	fdOut << "\n                                #@%%%%%:;;";
	fdOut << "\n                                %@@%%%::;";
	fdOut << "\n                                %@@@%(o);  . '         ";
	fdOut << "\n                                %@@@o%;:(.,'         ";
	fdOut << "\n                            `.. %@@@o%::;         ";
	fdOut << "\n                               `)@@@o%::;         ";
	fdOut << "\n                                %@@(o)::;        ";
	fdOut << "\n                               .%@@@@%::;         ";
	fdOut << "\n                               ;%@@@@%::;.          ";
	fdOut << "\n                              ;%@@@@%%:;;;. ";
	fdOut << "\n                          ...;%@@@@@%%:;;;;,..    ";

	fdOut.close();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	std::cout << "Can't copy anything" << std::endl;
	other.getTarget();

	return *this;
}