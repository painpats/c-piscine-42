#include "Animal.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
Animal::Animal()
{
    _type = "Animal";
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

Animal::Animal(const std::string& type) {
    _type = type;
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

Animal::Animal(const Animal& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Animal::~Animal()
{
    std::cout << ">>>> Bye bye animal !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Animal& Animal::operator=(const Animal& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	Animal::getType(void) const {
	return _type;
}

void    Animal::setType(const std::string type) {
    _type = type;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    Animal::makeSound() const {
    std::cout << ">>>> nianianianiania" << std::endl;
}
