#include "Bureaucrat.hpp"

int	main()
{
/////////////////////////////////////////////////////////////////////
	std::cout << "\nGRADE INCREMENTING UNTIL TOO HIGH" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	try
	{
		Bureaucrat	elisabeth("Elisabeth", 3);
		elisabeth.incrementGrade(); // 2
		elisabeth.incrementGrade(); // 1
		std::cout << elisabeth << std::endl;
		elisabeth.incrementGrade(); // 0 -> throw error grade too high
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

/////////////////////////////////////////////////////////////////////
	std::cout << "\nGRADE TOO HIGH" << std::endl;
	std::cout << "--------------" << std::endl;
	try
	{
		Bureaucrat	nicole("Nicole", 0); // 0 -> throw error grade too high
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

/////////////////////////////////////////////////////////////////////
	std::cout << "\nGRADE DECREMENTING UNTIL TOO LOW" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	try
	{
		Bureaucrat yves("Yves", 148);
		yves.decrementGrade(); // 149
		yves.decrementGrade(); // 150
		std::cout << yves << std::endl;
		yves.decrementGrade(); // 151 -> throw error grade too low
		std::cout << yves << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

/////////////////////////////////////////////////////////////////////
	std::cout << "\nGRADE TOO LOW" << std::endl;
	std::cout << "-------------" << std::endl;
	try
	{
		Bureaucrat	rene("Rene", 152); // 152 -> throw error grade too low
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return 0;
}
