#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {
	private:
		Contact	_contacts[8];
		int		_index;
		
	public:
		PhoneBook(void);
		~PhoneBook();
		void	addContact();
		void	searchContact();
		void	contactInfo(Contact bro);

};

std::string	lengthChecker(std::string str);
std::string	perfectCase(int size);

#endif
