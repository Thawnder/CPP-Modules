#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure const & base);
		~Cure();

		Cure & operator=(Cure const & base);

		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif