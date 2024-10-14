#include "ScavTrap.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
ScavTrap::ScavTrap() : ClapTrap() 
{
	_name = "Casper";
	_energyPoints = 50;
	_attackDamage = 20;
    std::cout << "ScavTrap>> " << _name << " (created from ClapTrap) is ready to rumble" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_energyPoints = 50;
	_attackDamage = 20;
    std::cout << "ScavTrap>> " << _name << " (created from ClapTrap) is ready to rumble" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
ScavTrap::~ScavTrap() {
    if (_hitPoints == 0 || _energyPoints == 0)
        std::cout << "ScavTrap>> " << _name << " didn't make it :/" << std::endl;
    else
        std::cout << "ScavTrap>> " << _name << " is the last survivor !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
ScavTrap& ScavTrap::operator=(const ScavTrap& overload) {
	if (this == &overload)
		return *this;
	_name = overload._name;
	_hitPoints = overload._hitPoints;
	_energyPoints = overload._energyPoints;
	_attackDamage = overload._attackDamage;
	return *this;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void    ScavTrap::guardGate() {
    std::cout << "ScavTrap>> Mode [GATE KEEPER] is now activated" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0)
	{	
		std::cout << "ScavTrap>> " << _name << " attacks " << target << ", causing [" << _attackDamage << "] points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap>> " << _name << " can't attack because he died :/" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap>> " << _name << " can't attack because he is exhausted :o" << std::endl;
}

