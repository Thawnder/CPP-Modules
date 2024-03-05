#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string _file;
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string input);
		BitcoinExchange(BitcoinExchange const & base);
		~BitcoinExchange();

		BitcoinExchange & operator=(BitcoinExchange const & base);

		void data_init();
		void exchange();
		int badInput(std::string str);
		int checkInput(std::string line);

		std::string prevDate(std::string date);
		double getValue(std::string date);
		void setFile(std::string name);
};