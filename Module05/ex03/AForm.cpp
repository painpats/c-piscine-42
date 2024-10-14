#include "AForm.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
AForm::AForm() : _name("Default"), _signature(0), _gradeSign(42), _gradeExec(150) {
    std::cout << "An AForm is printed." << std::endl;
}
AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name), _signature(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (_gradeSign < 1 || _gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << "AForm " << _name << "(s[" << _gradeSign <<"], e[" << _gradeExec << "]) is created." << std::endl;
}
AForm::AForm(const AForm& copy) : _name(copy.getName()), _signature(copy.getSignature()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec()) {
	*this = copy;
	std::cout << "AForm " << _name << " : Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
AForm::~AForm() {
	std::cout << "A AForm has been destroyed." << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
AForm&	AForm::operator=(const AForm&copy) {
	_signature = copy.getSignature();
	return *this;
}
std::ostream& operator<<(std::ostream& o, const AForm& f) {
	o << f.getName() << "'S AFORM INFORMATIONS :\n____gradeSign : " << f.getGradeSign() << "\n____gradeExec : " << f.getGradeExec() << "\n____signature : " << f.getSignature();
	return o;
}

////////// GETTER-SETTER ////////////////////////////////////////////
const std::string AForm::getName() const {
	return _name;
}
bool	AForm::getSignature() const {
	return _signature;
}
int	AForm::getGradeSign() const {
	return _gradeSign;
}
int	AForm::getGradeExec() const {
	return _gradeExec;
}

////////// EXCEPTIONS ///////////////////////////////////////////////
const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm: Invalid grade: the highest grade is 1";
}
const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm: Invalid grade: the lowest grade is 150";
}
const char *AForm::AFormSignException::what() const throw() {
	return "the AForm is already signed !";
}
const char *AForm::AFormUnsignedException::what() const throw() {
	return "AForm : Unsigned";
}

////////// FUNCTIONS ////////////////////////////////////////////////
void	AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	else if (_signature == true)
		throw AForm::AFormSignException();
	else
		_signature = true;
}
