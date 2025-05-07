#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

void BitcoinExchange::loadDatabase(const std::string& dbFile) 
{
	std::ifstream in(dbFile.c_str());
	if (!in)
		throw std::runtime_error("Error: could not open database file.");
	std::string line;
	std::getline(in, line);
	while (std::getline(in, line)) 
	{
		if (line.empty())
			continue;
		std::istringstream iss(line);
		std::string date, priceStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, priceStr))
			continue;
		double price = std::atof(priceStr.c_str());
		data_[date] = price;
	}
}

double BitcoinExchange::getRate(const std::string& date) const 
{
	std::map<std::string, double>::const_iterator it = data_.lower_bound(date);
	if (it != data_.end() && it->first == date)
		return it->second;
	if (it == data_.begin())
		throw std::out_of_range("no earlier date available");
	--it;
	return it->second;
}
