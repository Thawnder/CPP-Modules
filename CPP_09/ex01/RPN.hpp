#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

class RPN
{
	private:
		std::string _exp;
		std::stack<int> _stack;
	public:
		RPN();
		RPN(std::string exp);
		RPN(RPN const & base);
		~RPN();

		RPN & operator=(RPN const & base);

		int checkExp();
		void setExp(std::string exp);
		void calc();
};
