#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
/////////////////////////////////////////////////////////////////////
	try
	{
		Intern	someRandomIntern;
		AForm	*scf;
		AForm	*rrf;
		AForm	*ppf;
		AForm	*wf;
		Bureaucrat	jerome("Jerome", 1);

		std::cout << ".-------------------------.\n| SHRUBBERY CREATION FORM |" << std::endl;
		std::cout << ".-------------------------." << std::endl;

			scf = someRandomIntern.makeForm("shrubbery creation", "Andrew");
			if (scf)
			{
				jerome.signForm(*scf);
				jerome.executeForm(*scf);
				delete scf;
			}

		std::cout << "\n.-----------------------.\n| ROBOTOMY REQUEST FORM |" << std::endl;
		std::cout << ".-----------------------." << std::endl;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			if (rrf)
			{
				jerome.signForm(*rrf);
				jerome.executeForm(*rrf);
				delete rrf;
			}

		std::cout << "\n.--------------------------.\n| PRESIDENTIAL PARDON FORM |" << std::endl;
		std::cout << ".--------------------------." << std::endl;

			ppf = someRandomIntern.makeForm("presidential pardon", "Denver");
			if (ppf)
			{
				jerome.signForm(*ppf);
				jerome.executeForm(*ppf);
				delete ppf;
			}

		std::cout << "\n.-------------.\n| WRONG AFORM |" << std::endl;
		std::cout << ".-------------." << std::endl;
		
			wf = someRandomIntern.makeForm("Wrong AForm", "Everly");
			if (wf)
			{
				jerome.signForm(*wf);
				jerome.executeForm(*wf);
				delete wf;
			}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
