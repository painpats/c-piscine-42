#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# include <iostream>
# include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weaponA;
	public:
		HumanA(std::string name, Weapon& weaponA);
		~HumanA();
		void	attack();
};

#endif