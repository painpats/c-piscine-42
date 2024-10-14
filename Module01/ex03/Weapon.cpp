#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType() const
{
    const std::string&    typeREF = _type;
    return typeREF;
}

void	Weapon::setType(std::string type)
{
    this->_type = type;
}
