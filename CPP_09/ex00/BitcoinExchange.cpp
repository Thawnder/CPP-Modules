#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _file("") {
	data_init();
}

BitcoinExchange::BitcoinExchange(std::string input): _file(input) {
	data_init();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & base) { *this = base; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & base) {
	if (this != &base)
	{
		_file = base._file;
		_data.clear();
		_data = base._data;
	}
	return *this;
}

void BitcoinExchange::data_init() {
	std::ifstream	file;
	char			tmp[1024];

	file.open("./data.csv");
	if (!file)
	{
		std::cout << "The data file data.csv does not exist." << std::endl;
		return ;
	}

	file.getline(tmp, 1024);
	while (!file.eof())
	{
		file.getline(tmp, 1024);
		if (!tmp[10] || tmp[10] != ',')
		{
			std::cout << "The data file data.csv is corrupted." << std::endl;
			file.close();
			return ;
		}
		_data[static_cast<std::string>(tmp).substr(0,10)] = atof(&tmp[11]);
	}
	file.close();
}

void BitcoinExchange::exchange() {
	if (_file.empty())
	{
		std::cout << "Input file undefined. (Use setFile function in the program)." << std::endl;
		return ;
	}
	
	std::ifstream	file;
	std::string		tmp;

	file.open(_file.c_str());
	if (!file)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::getline(file, tmp);
	while (!file.eof())
	{
		std::getline(file, tmp);
		if (checkInput(tmp) == -1)
			continue;
		std::cout << tmp.substr(0, 10) << " => " << &tmp[13] << " = " << atof(&tmp[12]) * getValue(tmp.substr(0,10)) << std::endl;
	}
	file.close();
}

int	BitcoinExchange::badInput(std::string str) {

	if (!str[0] || (str[0] && (str[0] == '\n' || !isdigit(str[0]))))
		return 1;
	if (str.size() < 14 || str[4] != '-' || str[7] != '-' || str[11] != '|')
		return 1;

	int dot = 0;
	for (size_t i = 12; i < str.size(); i++)
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot > 1)
		return 1;

	int	year = atoi((str.substr(0, 4)).c_str());
	int	month = atoi((str.substr(5, 2)).c_str());
	int	day = atoi((str.substr(8, 2)).c_str());

	if (year < 2009 /*|| year > 2023*/)
		return 1;
	else if (month < 1 || month > 12)
		return 1;
	else if (day < 1 || day > 31)
		return 1;
	return 0;
}

int BitcoinExchange::checkInput(std::string line) {
	double value = getValue(line.substr(0,10));

	if (value == -1 || badInput(line))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	double num = atof(&line[12]);

	if (num < 0 || num > 1000)
	{
		if (num < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return -1;
	}

	return 0;
}

std::string BitcoinExchange::prevDate(std::string date) {
	int	year = atoi((date.substr(0, 4)).c_str());
	int	month = atoi((date.substr(5, 2)).c_str());
	int	day = atoi((date.substr(8, 2)).c_str());

	if (--day == 0)
	{
		day = 31;
		if (--month == 0)
		{
			month = 12;
			if (--year <= 2008)
				return "Error";
		}
	}
	std::ostringstream res;
    res << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
	date = res.str();
	return (date);
}

double BitcoinExchange::getValue(std::string date) {
	std::map<std::string, double>::const_iterator::iterator	it;
	
	it = this->_data.find(date);
	if (it == this->_data.end()) 
	{	
		while (it == this->_data.end())
		{
			date = prevDate(date);
			if (date == "Error")
				return -1;
			it = this->_data.find(date);
		}
	}
	return (it->second);
}

void BitcoinExchange::setFile(std::string name) { _file = name; }