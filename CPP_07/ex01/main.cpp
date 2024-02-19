#include "iter.hpp"

# include <iostream>

void incr(int &a)
{
	a += 2;
}

int main(void){
	int tab[4] = {1, 2, 3, 4};

	iter(tab, 4, &incr);

	for (int i = 0; i < 4; i++)
		std::cout << tab[i] << std::endl;
}