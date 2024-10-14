#include "ShrubberyCreationForm.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrub", 145, 137) {
	_target = "Default";
	std::cout << "Shrubbery: Default constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrub", 145, 137) {
	_target = target;
	std::cout << "Shrubbery: Constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()) {
	_target = copy.getTarget();
	std::cout << "Shrubbery: Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery: Destructor called" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	_target = copy.getTarget();
	return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	ShrubberyCreationForm::getTarget() const {
	return _target;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void	ShrubberyCreationForm::execute(const Bureaucrat& exec) const {
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	else if (getSignature() == false)
		throw AForm::AFormUnsignedException();
	else
	{
		std::ofstream	o;
		std::string	filename = getTarget() + "_shrubbery";
		o.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
		if (o.fail())
		{
			std::cout << "Error: Can't open the outfile" << std::endl;
			return ;
		}
		o << "               ,@@@@@@@," << std::endl;
		o << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		o << "    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
		o << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88888888/88'" << std::endl;
		o << "   %&&%&%&/%&&%@@\\@@/ /@@@88888888888'" << std::endl;
		o << "   %&&%/ %&%%&&@@\\ V /@@' `8888 `/88'" << std::endl;
		o << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		o << "       |o|        | |         | |" << std::endl;
		o << "       |.|        | |         | |" << std::endl;
		o << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		o.close();
	}
}
