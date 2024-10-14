#include "Zombie.hpp"

int main()
{
	int	number = 0;
    Zombie* zomzom = zombieHorde(number, "Titou");

	if (zomzom == NULL) {
		return -1;
	}

	for (int i = 0; i < number; i++)
		zomzom[i].announce();
	delete [] zomzom;
    return 0;
}
