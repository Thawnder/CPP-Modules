#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap one = ClapTrap("Billy");
	ClapTrap two = ClapTrap("Jackson");
	ScavTrap three = ScavTrap("Macy");
	FragTrap four = FragTrap("Jay");
	DiamondTrap five = DiamondTrap("Blake");

	one.attack("Jackson");
	two.takeDamage(0);
	two.beRepaired(10);
	three.attack("Billy");
	one.takeDamage(20);
	one.attack("Macy");
	three.beRepaired(1);
	three.guardGate();
	four.attack("Macy");
	three.takeDamage(four.getAtk());
	four.attack("Macy");
	three.takeDamage(four.getAtk());
	four.attack("Macy");
	three.takeDamage(four.getAtk());
	four.attack("Macy");
	three.takeDamage(four.getAtk());
	four.highFivesGuys();
	five.highFivesGuys();
	std::cout << "Jay and Blake made a high five and shook the earth," << std::endl << "and thus it is the birth of a friendship, nay, a brotherhood." << std::endl << std::endl;
	five.whoAmI();

	return 0;
}