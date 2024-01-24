#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <string.h>
# include <iomanip>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const & base);
		~Brain();

		Brain& operator=(Brain const & base);
		
		void	setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

#endif