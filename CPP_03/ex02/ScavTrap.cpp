#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap string constructor called" << std::endl << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
}

ScavTrap::ScavTrap(ScavTrap const & base): ClapTrap(base) {
	std::cout << "ScavTrap copy constructor called" << std::endl << std::endl;
	*this = base;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& 	ScavTrap::operator=(ScavTrap const & base) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &base)
	{
		this->_name = base.getName();
		this->_atk = base.getAtk();
		this->_hp = base.getHp();
		this->_ep = base.getEp();
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " points of damage." << std::endl;
		this->_ep--;
		std::cout << this->_ep << " ep remaining." << std::endl << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't attack anymore." << std::endl << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper Mode." << std::endl << std::endl;
}
