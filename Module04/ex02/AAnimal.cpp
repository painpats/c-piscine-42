#include "AAnimal.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
AAnimal::AAnimal()
{
    _type = "AAnimal";
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

AAnimal::AAnimal(const std::string& type) {
    _type = type;
    std::cout << ">>>> Welcome in the jungle " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
AAnimal::~AAnimal()
{
    std::cout << ">>>> Bye bye AAnimal !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
AAnimal& AAnimal::operator=(const AAnimal& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// GETTER-SETTER ////////////////////////////////////////////
std::string	AAnimal::getType(void) const {
	return _type;
}

void    AAnimal::setType(const std::string type) {
    _type = type;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    AAnimal::makeSound() const {
    std::cout << ">>>> nianianianiania" << std::endl;
}
