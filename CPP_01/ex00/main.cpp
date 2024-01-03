#include "Zombie.hpp"

int main(void)
{
	Zombie *newZ = newZombie("Coolio");
	randomChump("Hagrid");

	delete newZ;
}