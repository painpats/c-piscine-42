#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signature;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		AForm();
		AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& copy);
		virtual ~AForm();

		AForm&	operator=(const AForm& copy);

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

		class AFormSignException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class AFormUnsignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void	beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat const& exec) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const AForm& f);

#endif
