#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Parameter error. The execution format is: ./RPN [expression between quotes]" << std::endl;
		return -1 ;
	}

	std::cout << "--------------TEST 1: Default Constructor--------------" << std::endl << std::endl;

	RPN rpn1 = RPN();

	rpn1.calc();

	rpn1.setExp(argv[1]);

	rpn1.calc();

	std::cout << std::endl << "--------------TEST 2: String Constructor--------------" << std::endl << std::endl;

	RPN rpn2 = RPN((std::string) argv[1]);

	rpn2.calc();

	std::cout << std::endl << "--------------TEST 3: Copy Constructor--------------" << std::endl << std::endl;

	RPN rpn3 = rpn2;

	rpn3.calc();
	
	return 0;
}