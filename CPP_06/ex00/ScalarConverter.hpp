#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <cmath>

class ScalarConverter
{
	protected:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & base);
		ScalarConverter & operator=(ScalarConverter const & base);
		~ScalarConverter();

	public:
		static void convert(std::string src);
		int type;
		static int isInt(std::string src);
		static int isFloat(std::string src);
		static int isDouble(std::string src);
};


#endif