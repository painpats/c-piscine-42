#include "FragTrap.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
FragTrap::FragTrap() : ClapTrap()
{
	_name = "Casper";
	_energyPoints = 100;
	_attackDamage = 30;
    std::cout << "FragTrap>> " << _name << " (created from ClapTrap) is coming" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_energyPoints = 100;
	_attackDamage = 30;
    std::cout << "FragTrap>> " << _name << " (created from ClapTrap) is coming" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) {
    *this = copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
FragTrap::~FragTrap() {
    if (_hitPoints == 0 || _energyPoints == 0)
        std::cout << "FragTrap>> " << _name << " is suffocated :/" << std::endl;
    else
        std::cout << "FragTrap>> " << _name << " is laughting" << std::endl;
}

////////// OPERATOR /////////////////////////////////////////////////
FragTrap& FragTrap::operator=(const FragTrap& overload) {
	if (this == &overload)
		return *this;
	_name = overload._name;
	_hitPoints = overload._hitPoints;
	_energyPoints = overload._energyPoints;
	_attackDamage = overload._attackDamage;
	return *this;
}

////////// FUNCTION /////////////////////////////////////////////////
void    FragTrap::highFivesGuy() {
    std::cout << "FragTrap>> " << _name << " asks for a high five" << std::endl;
}
