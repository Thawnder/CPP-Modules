#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	const Animal *tab[10];

	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();

	for (int i = 0; i < 10; i++)
		tab[i]->makeSound();

	for (int i = 0; i < 10; i++)
		delete tab[i];

	std::cout << std::endl;

	Cat copy;
	Cat cat;

	cat.setIdeas("Meow");
	for (int i = 0; i < 100; i++)
		std::cout << cat.getBrain()->getIdea(i) << std::endl;
	std::cout << std::endl;

	copy = cat;
	copy.setIdeas("Nyan");

	for (int i = 0; i < 100; i++)
		std::cout << cat.getBrain()->getIdea(i) << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << copy.getBrain()->getIdea(i) << std::endl;

	return 0;
}
