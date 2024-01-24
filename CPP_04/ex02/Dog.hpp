#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(Dog const & base);
		~Dog();

		Dog& operator=(Dog const & base);

		void setIdeas(std::string str);
		Brain* getBrain() const;
		void makeSound() const;
};

#endif