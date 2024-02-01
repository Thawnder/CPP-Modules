#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap string constructor called" << std::endl << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;
}

FragTrap::FragTrap(FragTrap const & base): ClapTrap(base) {
	std::cout << "FragTrap copy constructor called" << std::endl << std::endl;
	*this = base;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& 	FragTrap::operator=(FragTrap const & base) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &base)
	{
		this->_name = base.getName();
		this->_atk = base.getAtk();
		this->_hp = base.getHp();
		this->_ep = base.getEp();
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " is asking for a high five." << std::endl << std::endl;
}