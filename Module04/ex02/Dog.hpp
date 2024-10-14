#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain			*_brain;
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& copy);
		~Dog();

		Dog& operator=(const Dog& copy);

		void	makeSound() const;
		Brain&	getBrain(void) const;
		void	setIdea(std::string idea);
		void	showIdea(unsigned int i);
};

#endif