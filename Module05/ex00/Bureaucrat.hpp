#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
	{
	private:
		const std::string	_name;
		int					_grade; // 1 to 150

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& copy);

		const std::string	getName() const;
		int			getGrade() const;

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
		
		void	incrementGrade();
		void	decrementGrade();
	};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif
