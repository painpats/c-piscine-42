#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <ctime>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);

		std::string	getTarget() const;

		void		execute(Bureaucrat const &exec) const;
};

#endif