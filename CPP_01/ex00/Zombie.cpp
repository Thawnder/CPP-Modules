#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void){
	std::cout << this->_name << " has been destroyed." << std::endl;
}

Zombie::Zombie(std::string name){
	this->_name = name;
	this->announce();
}

void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}