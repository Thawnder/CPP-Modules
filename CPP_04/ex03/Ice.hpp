#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice
{
	private:

	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const & base);
		~Ice();

		Ice & operator=(Ice const & base);
};

#endif