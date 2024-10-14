#include "ScavTrap.hpp"

int main()
{
    ClapTrap    joe("Joe");
    ScavTrap    cacahuete("Cacahuete");
    ScavTrap    bob("Bob");
    ScavTrap    pistache("Pistache");

    std::cout << std::endl;
    cacahuete.guardGate();

    std::cout << "\nJOE VS CACAHUETE" << std::endl;
    std::cout << "----------------" << std::endl;
    joe.attack("Cacahuete");
    cacahuete.takeDamage(0);
    cacahuete.attack("Joe");
    joe.takeDamage(20);
    joe.attack("Cacahuete");

    std::cout << "\nBOB VS PISTACHE" << std::endl;
    std::cout << "----------------" << std::endl;
    pistache.attack("Bob");
    bob.takeDamage(20);
    for (int i=0 ; i<4 ; i++)
    {
        pistache.attack("Bob");
        bob.takeDamage(20);
    }
    bob.beRepaired(1);

    std::cout << "\nCACAHUETE VS PISTACHE" << std::endl;
    std::cout << "---------------------" << std::endl;
    for (int j=0 ; j<49 ; j++)
        cacahuete.beRepaired(1);
    pistache.attack("Cacahuete");
    cacahuete.takeDamage(20);
    cacahuete.attack("Pistache");

    std::cout << std::endl;
}
