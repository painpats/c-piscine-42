#include "Dog.hpp"
//🐶
////////// CONSTRUCTORS /////////////////////////////////////////////
Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "🐶>> " << _type << " is approaching" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
    _type = type;
    std::cout << "🐶>> " << _type << " is approaching" << std::endl;
}

Dog::Dog(const Dog& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Dog::~Dog()
{
    std::cout << "🐶>> " << _type << " runs off with a string of sausages" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Dog& Dog::operator=(const Dog& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void    Dog::makeSound() const {
    std::cout << "🐶>> " << _type << " : ouaf ouaf" << std::endl;
}