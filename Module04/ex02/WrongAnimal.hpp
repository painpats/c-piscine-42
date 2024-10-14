#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& copy);

		std::string	getType(void) const;
		void		setType(const std::string type);

		void	makeSound() const;
};

#endif