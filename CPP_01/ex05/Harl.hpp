#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <string.h>
# include <iomanip>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl();
		~Harl();
		std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*lvl[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
		void complain(std::string level);
};

#endif