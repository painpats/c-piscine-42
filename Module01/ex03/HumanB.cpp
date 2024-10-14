#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL)
{}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weaponB)
{
    this->_weaponB = &weaponB;
}

Weapon*	HumanB::getWeapon(void)
{
    return (_weaponB);
}

void    HumanB::attack()
{
    if (_weaponB == NULL)
    {
        std::cout << _name << " asks for a rock-paper-scissors" << std::endl;
    } 
    else
    {
        std::cout << _name << " attacks with his " << _weaponB->getType() << std::endl;
    }
}
