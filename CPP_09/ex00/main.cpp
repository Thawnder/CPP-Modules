#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Parameter error. The execution format is: ./btc [input file]" << std::endl;
		return -1 ;
	}

	std::cout << "--------------TEST 1: Default Constructor--------------" << std::endl << std::endl;

	BitcoinExchange btc1 = BitcoinExchange();

	btc1.exchange();

	btc1.setFile(argv[1]);

	btc1.exchange();

	std::cout << std::endl << "--------------TEST 2: String Constructor--------------" << std::endl << std::endl;

	BitcoinExchange btc2 = BitcoinExchange((std::string) argv[1]);

	btc2.exchange();

	std::cout << std::endl << "--------------TEST 3: Copy Constructor--------------" << std::endl << std::endl;

	BitcoinExchange btc3 = btc2;

	btc3.exchange();
	
	return 0;
}