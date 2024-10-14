#include "RobotomyRequestForm.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robot", 72, 45) {
	_target = "Default";
    std::srand(time(0));
	std::cout << "Robotomy: Default constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45) {
    _target = target;
    std::srand(time(0));
	std::cout << "Robot: Constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm::AForm(copy) {
	_target = copy._target;
	std::cout << "Robot: Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robot: Destructor called" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    AForm::operator=(copy);
    _target = copy._target;
    return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    RobotomyRequestForm::execute(Bureaucrat const& exec) const {
	if (exec.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	else if (getSignature() == false)
		throw AForm::AFormUnsignedException();
    int	nbr = std::rand() % 2;
	if (nbr == 0)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " has not been robotomized..." << std::endl;
}
