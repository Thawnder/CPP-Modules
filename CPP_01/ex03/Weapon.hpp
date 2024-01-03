#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		~Weapon();
		Weapon(std::string str);
		std::string const & getType() const;
		void setType(std::string str);
};

#endif