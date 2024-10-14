#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_index = 0;
	std::cout << "Bidibipbip 🤖 ([en. trad]: Welcome in this beautiful Phonebook)" << std::endl;
	std::cout << "[ADD] [SEARCH] [EXIT]" << std::endl;
}
PhoneBook::~PhoneBook() {
	std::cout << "Bidibyebye 🤖 ([en. trad]: Goodbye my friend, it's been a pleasure)" << std::endl;
}

///// FUNCTIONS ///////////////////////////////////////////////////
void	PhoneBook::addContact()
{
	std::string str = "";
	std::cout << "Bidibopbop 🤖 ([en. trad]: Enter your new contact informations)" << std::endl;
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "[👾] First Name 	: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_contacts[this->_index % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "[👾] Last Name 		: ";
		std::getline(std::cin, str);
		if (str != "")
			this->_contacts[this->_index % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "[👾] Nickname 		: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setNickname(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "[👾] Phone Number 	: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setPhoneNumber(str);
	}
	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << "[👾] Darkest Secret 	: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].setDarkestSecret(str);
			std::cout << _contacts[_index % 8].getFirstName() << " is now on your friend's list :) "  << std::endl;
		}
	}
	this->_index++;
}

// function that check if length[str] < 10, if not it puts a '.'
std::string	lengthChecker(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[str.size() - 1] = '.';
	}
	return (str);
}

// function that put space(s) before the string if length[str] < 10
std::string perfectCase(int size)
{
	std::string	str;

	while (size > 0)
	{
		str.append(" ");
		size--;
	}
	return (str);
}

int	displaySearchTab(Contact mate[8])
{
	char		bro;
	int			i;
	std::string	str;

	bro = '0';
	i = 0;
	str = bro;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	while (++bro <= '8')
	{
		if (mate[bro - 1 - '0'].getFirstName().size() && ++i)
		{
			str = bro;
			str = lengthChecker(str);
			std::cout << "|" << perfectCase(10 - str.size()) << str;
			str = lengthChecker(mate[bro - 1 - '0'].getFirstName());
			std::cout << "|" << perfectCase(10 - str.size()) << str;
			str = lengthChecker(mate[bro - 1 - '0'].getLastName());
			std::cout << "|" << perfectCase(10 - str.size()) << str;
			str = lengthChecker(mate[bro - 1 - '0'].getNickname());
			std::cout << "|" << perfectCase(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << std::endl;
	return i;
}

void	PhoneBook::searchContact()
{
	std::string	s;

	s = _index;
	if (!displaySearchTab(_contacts))
	{
		std::cout << "Bidibepcheh 🤖 ([en. trad: Outch... You don't have any friends...])" << std::endl;
		std::cout << std::endl;
		return ;
	}
	while (!std::cin.eof() && !s.empty())
	{
		std::cout << std::endl;
		std::cout << "Bidiboupboup 🤖 ([en. trad]: Who do you want ?) : ";
		if (!s.empty() && std::getline(std::cin, s))
		{
			if (s.size() == 1 && (s[0] >= '1' && s[0] <= '8') && this->_contacts[s[0] - 1 - '0'].getFirstName().size())
				break ;
		}
		if (!s.empty())
			std::cout << "Bidibigflop... 🤖 ([en. trad]: You are asking for an imaginary friend...)" << std::endl;
	}
	std::cout << std::endl;
	if (!std::cin.eof() && !s.empty())
		this->contactInfo((this->_contacts[s[0] - 1 - '0']));
}

void	PhoneBook::contactInfo(Contact bro)
{
	if (!bro.getFirstName().size())
	{
		std::cout << "Bidibepcheh 🤖 ([en. trad: Outch... You don't have any friends...])" << std::endl;
		std::cout << std::endl;
		return ;
	}
	else
	{
		std::cout << "Bidibapbap 🤖 ([en. trad]: Here are the informations about your mate)" << std::endl;
		std::cout << "[👾] First Name 	: " << bro.getFirstName() << std::endl;
		std::cout << "[👾] Last Name 		: " << bro.getLastName() << std::endl;
		std::cout << "[👾] Nickname 		: " << bro.getNickname() << std::endl;
		std::cout << "[👾] Phone Number 	: " << bro.getPhoneNumber() << std::endl;
		std::cout << "[👾] Darkest Secret 	: " << bro.getDarkestSecret() << std::endl;
	}
}
