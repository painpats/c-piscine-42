#include "Contact.hpp"

Contact::Contact() {
}
Contact::~Contact() {
}

///// SETTER //////////////////////////////////////////////////////
void Contact::setFirstName(std::string input)
{
	this->_first_name = input;
}
void Contact::setLastName(std::string input) {
	this->_last_name = input;
}
void Contact::setNickname(std::string input) {
	this->_nickname = input;
}
void Contact::setPhoneNumber(std::string input) {
	this->_phone_number = input;
}
void Contact::setDarkestSecret(std::string input) {
	this->_darkest_secret = input;
}

//// GETTER ///////////////////////////////////////////////////////
std::string Contact::getFirstName() {
	return (_first_name);
}
std::string Contact::getLastName() {
	return (_last_name);
}
std::string Contact::getNickname() {
	return (_nickname);
}
std::string Contact::getPhoneNumber() {
	return (_phone_number);
}
std::string Contact::getDarkestSecret() {
	return (_darkest_secret);
}
