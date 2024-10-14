#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string	input;
	PhoneBook	fonebouque;

	while (input != "EXIT")
	{
		std::cout << "MyPhoneBook > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			fonebouque.addContact();
		else if (input == "SEARCH")
			fonebouque.searchContact();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		else if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			std::cout << "Bidiiiiiiiiiiii... 🤖 ([en. trad]: Invalid command !)" << std::endl;
	}
	return (0);
}
