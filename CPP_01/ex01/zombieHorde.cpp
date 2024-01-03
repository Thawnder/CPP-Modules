#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	Zombie *tab = new Zombie[N];

	for (int i = 0; i < N; ++i) {
    	tab[i].setName(name);
    }

	return tab;
}