#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hp(10), _ep(10), _atk(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _atk(0) {
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & base) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = base;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& 	ClapTrap::operator=(ClapTrap const & base) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &base)
	{
		this->_name = base.getName();
		this->_atk = base.getAtk();
		this->_hp = base.getHp();
		this->_ep = base.getEp();
	}
	return *this;
}

std::string	ClapTrap::getName(void) const {
	return this->_name;
}

int ClapTrap::getHp(void) const {
	return this->_hp;
}

int ClapTrap::getEp(void) const {
	return this->_ep;
}

int ClapTrap::getAtk(void) const {
	return this->_atk;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " points of damage." << std::endl;
		this->_ep--;
		std::cout << this->_ep << " ep remaining." << std::endl << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't attack anymore." << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage." << std::endl;
		this->_hp -= amount;
		if (this->_hp <= 0)
			std::cout << "ClapTrap " << this->_name << " died." << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << "Claptrap " << this->_name << " is already dead." << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp > 0 && this->_ep > 0)
	{
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself and gets " << amount << " more hp." << std::endl;
		this->_ep--;
		std::cout << this->_ep << " ep remaining." << std::endl << std::endl;
	}
	else if (this->_hp > 0 && this->_ep <= 0)
		std::cout << "ClapTrap " << this->_name << " doesn't have enough ep to repair itself" << std::endl << std::endl;
	else if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead and can't repair itself." << std::endl << std::endl;
}