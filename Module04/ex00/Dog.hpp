#ifndef Dog_HPP
# define Dog_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& copy);
		~Dog();

		Dog& operator=(const Dog& copy);

		void	makeSound() const;
};

#endif