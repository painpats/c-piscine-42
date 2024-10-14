#include "Form.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Form::Form() : _name("Default"), _signature(false), _gradeSign(42), _gradeExec(150) {
    std::cout << "A Form is printed." << std::endl;
}
Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name), _signature(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (_gradeSign < 1 || _gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form " << _name << "(s[" << _gradeSign <<"], e[" << _gradeExec << "]) is created." << std::endl;
}
Form::Form(const Form& copy) : _name(copy.getName()), _signature(copy.getSignature()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()) {
	*this = copy;
	std::cout << "Form " << _name << " : Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Form::~Form() {
	std::cout << "A Form has been destroyed." << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Form&	Form::operator=(const Form&copy) {
	_signature = copy.getSignature();
	return *this;
}
std::ostream& operator<<(std::ostream& o, const Form& f) {
	o << f.getName() << "'S FORM INFORMATIONS :\n____gradeSign : " << f.getGradeSign() << "\n____gradeExec : " << f.getGradeExec() << "\n____signature : " << f.getSignature();
	return o;
}

////////// GETTER-SETTER ////////////////////////////////////////////
const std::string Form::getName() const {
	return _name;
}
bool	Form::getSignature() const {
	return _signature;
}
int	Form::getGradeSign() const {
	return _gradeSign;
}
int	Form::getGradeExec() const {
	return _gradeExec;
}

////////// EXCEPTIONS ///////////////////////////////////////////////
const char *Form::GradeTooHighException::what() const throw() {
	return "Form: Invalid grade: the highest grade is 1";
}
const char *Form::GradeTooLowException::what() const throw() {
	return "Form: Invalid grade: the lowest grade is 150";
}
const char *Form::FormSignException::what() const throw() {
	return "the Form is already signed !";
}

////////// FUNCTIONS ////////////////////////////////////////////////
void	Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	else if (_signature == true)
		throw Form::FormSignException();
	else
		_signature = true;
}
