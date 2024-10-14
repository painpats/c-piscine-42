#include "Dog.hpp"
//🐶
////////// CONSTRUCTORS /////////////////////////////////////////////
Dog::Dog() : Animal()
{
    _type = "Dog";
    std::cout << "🐶>> " << _type << " is approaching" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type)
{
    _type = type;
    std::cout << "🐶>> " << _type << " is approaching" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Dog::~Dog()
{
    if (this->_brain)
		delete _brain;
    std::cout << "🐶>> " << _type << " runs off with a string of sausages" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Dog& Dog::operator=(const Dog& overload) {
    if (this == &overload) {
        return *this;
	}
	_type = overload._type;
	_brain = new Brain();
	*_brain = *overload._brain;
	return *this;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    Dog::makeSound() const {
    std::cout << "🐶>> " << _type << " : ouaf ouaf" << std::endl;
}

Brain&	Dog::getBrain(void) const {
	return *_brain;
}

void	Dog::setIdea(std::string idea) {
	Brain&	dogBrain = getBrain();
	dogBrain.setIdea(idea);
	std::cout << "🐶>> " << _type << " got a new idea : " << idea << std::endl;
}

void	Dog::showIdea(unsigned int i) {
	Brain&	dogBrain = getBrain();
	dogBrain.showIdea(i);
}
