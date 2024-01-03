#include "Zombie.hpp"

int main(void)
{
	Zombie *tab = zombieHorde(10, "Passe-partout");
	for (int i = 0; i < 10; i++)
		tab[i].announce();
	delete[] tab;
}