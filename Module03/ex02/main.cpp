#include "FragTrap.hpp"

int main()
{
    FragTrap    rudolf("Rudolf");
    FragTrap    krexuh("Krexuh");

    krexuh.highFivesGuy();
    rudolf.attack("Krexuh");
    for (int i=0 ; i<4 ; i++)
        krexuh.takeDamage(30);

    return 0;
}