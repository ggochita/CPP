#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_btcData;
public:
	BitcoinExchange();
	~BitcoinExchange();

	void loadDatabase();
    void processInput(const std::string& filename);
private:
    bool parseLine(const std::string& line, std::string& date, float& value);
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& valueStr, float& value);

    std::string trim(const std::string& str);

    float getRateForDate(const std::string& date);
};
