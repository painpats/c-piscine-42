#include "Brain.hpp"
//🧠
////////// CONSTRUCTORS /////////////////////////////////////////////
Brain::Brain()
{
	_ideaCount = 0;
    std::cout << "🧠>> The animal evolved" << std::endl;
}

Brain::Brain(const Brain& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
Brain::~Brain()
{
    std::cout << "🧠>> Brain goes *scouic* !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
Brain& Brain::operator=(const Brain& overload) {
    if (this == &overload) {
        return *this;
	}
	for (int i=0 ; i < 100; i++) {
		_ideas[i] = overload._ideas[i];
	}
    return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void	Brain::setIdea(std::string idea) {
	if (_ideaCount >= 100)
		std::cout << "🧠>> Lack of neurons" << std::endl;
	else {
		_ideas[_ideaCount] = idea;
		_ideaCount++;
	}
}

void	Brain::showIdea(unsigned int i) {
	if (i >= 100)
		std::cout << "🧠>> I'm just an animal, I can't think that much" << std::endl;
	else if (_ideas[i].empty())
		std::cout << "🧠>> [empty mind]" << std::endl;
	else
		std::cout << "🧠>> An idea just poped [" << _ideas[i] << "]" << std::endl;
}
