#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange 
{
public:
	void loadDatabase(const std::string& dbFile);
	double getRate(const std::string& date) const;
private:
	std::map<std::string, double> data_;
};

#endif
