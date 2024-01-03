#include "HumanB.hpp"

HumanB::HumanB(){
	this->_name = "";
	this->_weapon = NULL;
}

HumanB::~HumanB(){}

HumanB::HumanB(std::string name){
	this->_name = name;
	this->_weapon = NULL;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with their fists" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}