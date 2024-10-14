#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
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