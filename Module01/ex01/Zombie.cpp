#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "The horde is approaching >_<" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::call(std::string name)
{
    this->_name = name;
}
