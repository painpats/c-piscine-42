#include "ClapTrap.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
ClapTrap::ClapTrap() : _name("Casper"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap>> " << _name << " is ready to rumble" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap>> " << _name << " is ready to rumble" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
ClapTrap::~ClapTrap()
{
    if (_hitPoints == 0 || _energyPoints == 0)
        std::cout << "ClapTrap>> " << _name << " didn't make it :/" << std::endl;
    else
        std::cout << "ClapTrap>> " << _name << " is the last survivor !" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
ClapTrap& 	ClapTrap::operator=(const ClapTrap& overload) {
    if (this == &overload)
        return *this;
    _name = overload._name;
    _hitPoints = overload._hitPoints;
    _energyPoints = overload._energyPoints;
    _attackDamage = overload._attackDamage;
    return *this;
}

////////// FUNCTIONS ////////////////////////////////////////////////
void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0)
	{	
		std::cout << "ClapTrap>> " << _name << " attacks " << target << ", causing [" << _attackDamage << "] points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap>> " << _name << " can't attack because he died :/" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap>> " << _name << " can't attack because he is exhausted :o" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    long refreshedHitPoints = (long)_hitPoints - amount;
    if (refreshedHitPoints <= 0)
        refreshedHitPoints = 0;
    if (_hitPoints != 0)
    {
        std::cout << "ClapTrap>> " << _name << " takes [" << amount << "] of damage" << std::endl;
        std::cout << "        >> " << _name << " now have [" << refreshedHitPoints << "] hit point.s left..." << std::endl;
        _hitPoints = refreshedHitPoints;
    }
    else
        std::cout << "ClapTrap>> " << _name << " didn't make it :/" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0)
        std::cout << "ClapTrap>> " << _name << " can't repair himself because he died :/" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap>> " << _name << " can't be repaired because he is exhausted :o" << std::endl;
    else
    {
        long refreshedHitPoints = (long)_hitPoints + amount;
        if (refreshedHitPoints > 4294967295)
            refreshedHitPoints = 4294967295;
        std::cout << "ClapTrap>> " << "The good fairy helped " << _name << " repairing himself by adding [" << amount << "] to his hit point.s" << std::endl;
        std::cout << "        >> " << _name << " now have [" << refreshedHitPoints << "] hit point.s left !" << std::endl;
        _hitPoints += amount;
		int	refreshedEnergyPoints = _energyPoints - 1;
		std::cout << "        >> " << _name << " now have [" << refreshedEnergyPoints << "] energy point.s left !" << std::endl;
        _energyPoints--;
    }
}
