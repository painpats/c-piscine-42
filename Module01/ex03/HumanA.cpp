#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponA) : _name(name), _weaponA(weaponA)
{
    std::cout << _name << " takes the [" << _weaponA.getType() << "] as a weapon !" << std::endl;
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << _name << " attacks with his " << _weaponA.getType() <<std::endl;
}
