#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure
{
	private:

	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const & base);
		~Cure();

		Cure & operator=(Cure const & base);
};


#endif