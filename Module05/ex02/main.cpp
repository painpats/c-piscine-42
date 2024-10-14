#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
/////////////////////////////////////////////////////////////////////

	try
	{
		std::cout << ".-------------------------.\n| SHRUBBERY CREATION FORM |" << std::endl;
		std::cout << ".-------------------------." << std::endl;
		//145, 137
			Bureaucrat gerard("Gerard", 1);
			std::cout << gerard << std::endl;
			Bureaucrat patrice("Patrice", 150);
			std::cout << patrice << std::endl;
			std::cout << std::endl;

			ShrubberyCreationForm firstForm("F1");
			std::cout << firstForm << std::endl;
			ShrubberyCreationForm secondForm("F2");
			std::cout << secondForm << std::endl;
			std::cout << std::endl;

			gerard.signForm(firstForm);
			gerard.executeForm(firstForm);
			std::cout << std::endl;
			patrice.signForm(secondForm);
			patrice.executeForm(secondForm);	

			std::cout << std::endl;
	}
		catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

/////////////////////////////////////////////////////////////////////
	try
	{
		std::cout << ".-----------------------.\n| ROBOTOMY REQUEST FORM |" << std::endl;
		std::cout << ".-----------------------." << std::endl;
		//72,45
			Bureaucrat gerard("Gerard", 1);
			std::cout << gerard << std::endl;
			Bureaucrat patrice("Patrice", 150);
			std::cout << patrice << std::endl;
			std::cout << std::endl;

			RobotomyRequestForm firstForm("F1");
			std::cout << firstForm << std::endl;
			RobotomyRequestForm secondForm("F2");
			std::cout << secondForm << std::endl;
			std::cout << std::endl;

			gerard.signForm(firstForm);
			gerard.executeForm(firstForm);
			std::cout << std::endl;
			patrice.signForm(secondForm);
			patrice.executeForm(secondForm);

			std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

/////////////////////////////////////////////////////////////////////
	try
	{
		std::cout << ".--------------------------.\n| PRESIDENTIAL PARDON FORM |" << std::endl;
		std::cout << ".--------------------------." << std::endl;
		//25, 5
			Bureaucrat gerard("Gerard", 1);
			std::cout << gerard << std::endl;
			Bureaucrat patrice("Patrice", 150);
			std::cout << patrice << std::endl;
			std::cout << std::endl;

			PresidentialPardonForm firstForm("F1");
			std::cout << firstForm << std::endl;
			PresidentialPardonForm secondForm("F2");
			std::cout << secondForm << std::endl;
			std::cout << std::endl;

			gerard.signForm(firstForm);
			gerard.executeForm(firstForm);
			std::cout << std::endl;
			patrice.signForm(secondForm);
			patrice.executeForm(secondForm);

			std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
