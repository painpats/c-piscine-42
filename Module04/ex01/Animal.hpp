#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& copy);
		virtual ~Animal();

		Animal& operator=(const Animal& copy);

		std::string	getType(void) const;
		void		setType(const std::string type);
		
		virtual void	makeSound() const;
};

#endif
