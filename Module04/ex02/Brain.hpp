#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	protected:
		std::string		_ideas[100];
		unsigned int	_ideaCount;
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain& operator=(const Brain& overload);

		void	setIdea(std::string idea);
		void	showIdea(unsigned int i);
};

#endif