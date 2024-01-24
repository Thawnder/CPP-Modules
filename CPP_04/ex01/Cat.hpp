#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(Cat const & base);
		~Cat();

		Cat& operator=(Cat const & base);

		void setIdeas(std::string str);
		Brain *getBrain() const;
		void makeSound() const;
};

#endif