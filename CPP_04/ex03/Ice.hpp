#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice const & base);
		~Ice();

		Ice & operator=(Ice const & base);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif