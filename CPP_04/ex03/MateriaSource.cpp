#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	if (DEBUG)
		std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_book[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & base) {
	if (DEBUG)
		std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = base;
}

MateriaSource::~MateriaSource() {
	if (DEBUG)
		std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_book[i])
			delete this->_book[i];
	}
}


MateriaSource & MateriaSource::operator=(MateriaSource const & base) {
	if (this != &base)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_book[i])
				delete this->_book[i];
			this->_book[i] = base.getMateria(i)->clone();
		}
	}
	return *this;
}

AMateria* const & MateriaSource::getMateria(int i) const {
	return this->_book[i];
}

void MateriaSource::learnMateria(AMateria* materia) {
	int i;

	for (i = 0; this->_book[i]; i++);
	if (i < 4)
		this->_book[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	int	i;

	for (i = 0; this->_book[i] && this->_book[i]->getType() != type; i++);
	if (this->_book[i])
		return this->_book[i]->clone();
	std::cout << "The materia type " << type << " doesn't exist." << std::endl;
	return 0;
}
