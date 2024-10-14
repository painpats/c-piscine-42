#include "Cat.hpp"
//🐱
////////// CONSTRUCTORS /////////////////////////////////////////////
Cat::Cat() : AAnimal()
{
    _type = "Cat";
    std::cout << "🐱>> " << _type << " is approaching" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const std::string& type) : AAnimal(type)
{
    _type = type;
    std::cout << "🐱>> " << _type << " is approaching" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Cat::~Cat()
{
    delete _brain;
    std::cout << "🐱>> " << _type << " got scared and run away" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Cat& Cat::operator=(const Cat& overload) {
    if (this == &overload)
        return *this;
    _type = overload._type;
	_brain = new Brain();
	*_brain = *overload._brain;
    return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void    Cat::makeSound() const {
    std::cout << "🐱>> " << _type << " : miaw miaw" << std::endl;
}

Brain&	Cat::getBrain(void) const {
	return *_brain;
}

void	Cat::setIdea(std::string idea) {
	Brain&	catBrain = getBrain();
	catBrain.setIdea(idea);
	std::cout << "🐱>> " << _type << " got a new idea : " << idea << std::endl;
}

void	Cat::showIdea(unsigned int i) {
	Brain&	catBrain = getBrain();
	catBrain.showIdea(i);
}
