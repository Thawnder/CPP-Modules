#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	protected:
		std::string _name;
		AMateria *_inv[4];

	public:
		Character();
		Character(std::string name);
		Character(Character const & base);
		virtual ~Character();

		Character & operator=(Character const & base);

		std::string const & getName() const;
		AMateria* const & getInv(int i) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif