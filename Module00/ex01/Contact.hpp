#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		Contact(void);
		~Contact();

		// SETTER //
		void setFirstName(std::string input);
		void setLastName(std::string input);
		void setNickname(std::string input);
		void setPhoneNumber(std::string input);
		void setDarkestSecret(std::string input);
		
		// GETTER //
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif