#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

# include <iostream>
# include <string>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weaponB;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& weaponB);
		Weapon*	getWeapon(void);
		void	attack();
};

#endif