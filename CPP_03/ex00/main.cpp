#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap one = ClapTrap("Billy");
	ClapTrap two = ClapTrap("Jackson");

	one.attack("Jackson");
	two.takeDamage(0);
	two.beRepaired(10);

	return 0;
}