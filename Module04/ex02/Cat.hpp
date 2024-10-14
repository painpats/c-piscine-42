#ifndef Cat_HPP
# define Cat_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& copy);
		~Cat();

		Cat& operator=(const Cat& copy);

		void	makeSound() const;
		Brain&	getBrain(void) const;
		void	setIdea(std::string idea);
		void	showIdea(unsigned int i);
};

#endif