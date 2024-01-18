#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & base);
		~ScavTrap();
		
		ScavTrap& 	operator=(ScavTrap const & base);

		void attack(const std::string& target);
		void guardGate();
};

#endif