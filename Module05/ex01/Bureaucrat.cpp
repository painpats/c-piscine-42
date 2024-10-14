#include "Bureaucrat.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Bureaucrat::Bureaucrat() : _name("Default") {
	_grade = 1;
	std::cout << "A random Bureaucrat just walked in" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << "The Bureaucrat <" << _name << "> just walked in." << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {
	*this = copy;
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Bureaucrat::~Bureaucrat() {
	std::cout << "The Bureaucrat <" << _name << "> walked away" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy) {
	_grade = copy.getGrade();
	return *this;
}
std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

////////// GETTER-SETTER ////////////////////////////////////////////
const std::string	Bureaucrat::getName() const {
    return _name;
}
int	Bureaucrat::getGrade() const {
	return _grade;
}

////////// EXCEPTIONS ///////////////////////////////////////////////
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Invalid grade: the highest grade is 1";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Invalid grade: the lowest grade is 150";
}

////////// FUNCTIONS ////////////////////////////////////////////////
void	Bureaucrat::incrementGrade() {
	if (_grade > 1) {
		std::cout << "Incrementing <" << _name << ">'s grade" << std::endl;
		_grade--;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}
void	Bureaucrat::decrementGrade() {
	if (_grade < 150) {
		std::cout << "Decrementing <" << _name << ">'s grade" << std::endl;
		_grade++;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
void	Bureaucrat::signForm(Form& f) {
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat <" << _name << "> signed form :\n____" << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat <" << _name << "> couldn't sign form \n____" << f << "\n____because " << e.what() << std::endl;
	}
}
