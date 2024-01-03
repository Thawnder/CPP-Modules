#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::~Weapon(){}

Weapon::Weapon(std::string str){
	this->type = str;
}

std::string const & Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}