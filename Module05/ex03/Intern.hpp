#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& copy);
        ~Intern();

		Intern& operator=(const Intern& copy);

        class WrongNameException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        AForm	*makeForm(const std::string formName, const std::string formTarget);
};

#endif
