#include "Bureaucrat.hpp"

int	main()
{
/////////////////////////////////////////////////////////////////////	
	try
	{
		std::cout << ".-------------------------.\n| CREATION OF BUREAUCRATS |" << std::endl;
		std::cout << ".-------------------------." << std::endl;
		Bureaucrat	pierre("Pierre", 1);
		std::cout << pierre << std::endl;
		std::cout << std::endl;

		Bureaucrat	paul("Paul", 150);
		std::cout << paul << std::endl;
		std::cout << std::endl;

		Bureaucrat	jacques("Jacques", 42);
		std::cout << jacques << std::endl;
		std::cout << std::endl;


		std::cout << ".-------------------.\n| CREATION OF FORMS |" << std::endl;
		std::cout << ".-------------------." << std::endl;
		Form		firstForm("F1", 1, 42);
		std::cout << firstForm << std::endl;
		std::cout << std::endl;

		Form		secondForm("F2", 150, 42);
		std::cout << secondForm << std::endl;
		std::cout << std::endl;

		Form		thirdForm("F3", 42, 42);
		std::cout << thirdForm << std::endl;
		std::cout << std::endl;

		std::cout << ".-----------------.\n| FORM SIGNATURES |" << std::endl;
		std::cout << ".-----------------." << std::endl;
		pierre.signForm(firstForm);
		paul.signForm(secondForm);
		jacques.signForm(thirdForm);
		pierre.signForm(firstForm);
		pierre.signForm(secondForm);
		std::cout << std::endl;

		std::cout << ".-------------.\n| DESTRUCTORS |" << std::endl;
		std::cout << ".-------------." << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return 0;
}
