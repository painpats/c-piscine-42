#include "Intern.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Intern::Intern() {
    std::cout << "An Intern is arriving" << std::endl;
}
Intern::Intern(const Intern& copy) {
    *this = copy;
    std::cout << "Intern: Copy constructor called" << std::endl;
}
////////// DESTRUCTOR ///////////////////////////////////////////////
Intern::~Intern() {
    std::cout << "The Intern goes away" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
    return *this;
}

////////// EXCEPTIONS ///////////////////////////////////////////////
const char *Intern::WrongNameException::what() const throw() {
    return "Error: The name of the AForm doesn't exist.";
}

////////// FUNCTIONS ////////////////////////////////////////////////
AForm*	Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string	form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	size_t		i = 0;

	while (i<3 && form[i] != formName)
		i++;
	switch (i) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(formTarget);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(formTarget);
		default:
			throw Intern::WrongNameException();
	}
}
