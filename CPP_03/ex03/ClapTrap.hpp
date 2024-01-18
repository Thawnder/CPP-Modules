#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>

class ClapTrap
{
	protected:
		std::string _name;
		int _hp;
		int _ep;
		int _atk;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & base);
		virtual ~ClapTrap();

		ClapTrap& 	operator=(ClapTrap const & base);
		std::string	getName(void) const;
		int getHp(void) const;
		int getEp(void) const;
		int getAtk(void) const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif