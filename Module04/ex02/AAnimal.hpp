#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal& copy);

		std::string	getType(void) const;
		void		setType(const std::string type);
		
		virtual void	makeSound() const = 0;
		virtual Brain&	getBrain(void) const = 0;
};

#endif
