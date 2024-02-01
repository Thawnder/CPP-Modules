#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "DiamondTrap string constructor called" << std::endl << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atk = FragTrap::_atk;
}

DiamondTrap::DiamondTrap(DiamondTrap const & base): ClapTrap(base), ScavTrap(base), FragTrap(base) {
	std::cout << "DiamondTrap copy constructor called" << std::endl << std::endl;
	*this = base;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & base) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &base)
	{
		this->_name = base.getName();
		ClapTrap::_name = this->_name + "_clap_name";
		this->_ep = base.getEp();
		this->_hp = base.getHp();
		this->_atk = base.getAtk();
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "This is " << this->_name << " AKA " << ClapTrap::_name << ", and you're watching Disney Channel !" << std::endl << std::endl;
}