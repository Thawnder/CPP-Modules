#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	protected:
		AMateria *_book[4];
	public:

		MateriaSource();
		MateriaSource(MateriaSource const & base);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const & base);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		AMateria* const & getMateria(int i) const;
};


#endif