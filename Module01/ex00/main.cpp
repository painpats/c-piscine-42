#include "Zombie.hpp"

int main()
{
    Zombie	first_zombie = Zombie("Georges");
	Zombie*	second_zombie = newZombie("Thierry");

	first_zombie.announce();
	second_zombie->announce();
	randomChump("Jean-Jacques");
	delete second_zombie;
    return (0);
}
