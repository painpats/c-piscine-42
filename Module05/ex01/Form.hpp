#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signature;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form();
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form& copy);
		~Form();

		Form&	operator=(const Form& copy);

		const std::string	getName() const;
		bool				getSignature() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();

		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormSignException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void	beSigned(Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& o, const Form& f);

#endif
