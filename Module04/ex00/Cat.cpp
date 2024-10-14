#include "Cat.hpp"
//🐱
////////// CONSTRUCTORS /////////////////////////////////////////////
Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "🐱>> " << _type << " is approaching" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
    _type = type;
    std::cout << "🐱>> " << _type << " is approaching" << std::endl;
}

Cat::Cat(const Cat& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Cat::~Cat()
{
    std::cout << "🐱>> " << _type << " got scared and run away" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Cat& Cat::operator=(const Cat& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
    return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void    Cat::makeSound() const {
    std::cout << "🐱>> " << _type << " : miaw miaw" << std::endl;
}
