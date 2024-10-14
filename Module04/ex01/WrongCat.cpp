#include "WrongCat.hpp"
//🐯
////////// CONSTRUCTORS /////////////////////////////////////////////
WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "🐯>> " << _type << " is approaching" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
    _type = type;
    std::cout << "🐯>> " << _type << " is approaching" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
WrongCat::~WrongCat()
{
    std::cout << "🐯>> " << _type << " saw another prey and run away" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
WrongCat& WrongCat::operator=(const WrongCat& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void    WrongCat::makeSound() const {
    std::cout << "🐯>> " << _type << " : roar" << std::endl;
}
