#include "WrongAnimal.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
WrongAnimal::WrongAnimal()
{
    _type = "WrongAnimal";
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
    _type = type;
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
WrongAnimal::~WrongAnimal()
{
    std::cout << ">>>> Bye bye WrongAnimal !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	WrongAnimal::getType(void) const {
	return _type;
}

void    WrongAnimal::setType(const std::string type) {
    _type = type;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    WrongAnimal::makeSound() const {
    std::cout << ">>>> roar" << std::endl;
}
