#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap	john("John Cena");
    ClapTrap	dwayne("Dwayne Johnson");
    ClapTrap	casper("Casper");

    john.attack("Dwayne Johnson");
    dwayne.takeDamage(5);
	dwayne.beRepaired(2);
    john.attack("Dwayne Johnson");
    dwayne.takeDamage(7);
    dwayne.beRepaired(10);
    dwayne.attack("John Cena");
    john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.attack("Casper");
	john.beRepaired(10);
    return 0;
}
