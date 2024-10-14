#include "PresidentialPardonForm.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon", 25, 5) {
    _target = "Default";
	std::cout << "Presidential: Default constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5) {
    _target = target;
	std::cout << "Presidential: Constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm::AForm(copy) {
	_target = copy._target;
	std::cout << "Presidential: Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential: Destructor called" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    AForm::operator=(copy);
    _target = copy.getTarget();
    return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	PresidentialPardonForm::getTarget() const {
	return _target;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    PresidentialPardonForm::execute(Bureaucrat const& exec) const {
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	else if (getSignature() == false)
		throw AForm::AFormUnsignedException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
