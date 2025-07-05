#include "BitcoinExchange.hpp"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

bool isDigitsOnly(const std::string& s)
{
    for (size_t i = 0; i < s.length(); ++i)
	{
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void	BitcoinExchange::loadDatabase()
{
	std::ifstream 	file("data.csv");
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open a data file.");

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			break;
		std::stringstream	ss(line);
		std::string			date;
		std::string			strValue;
		float				value;

		std::getline(ss, date, ',');
		std::getline(ss, strValue, ',');

		value = std::stof(strValue);
		_btcData.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream input(filename.c_str());
	std::string line;
	
	if (!input.is_open())
		throw std::runtime_error("Error: could not open a input file.");
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (line.empty())
			continue;
	
		std::string date;
		float value;
		if (parseLine(line, date, value))
		{
			try {
				float rate = getRateForDate(date);
				std::cout << date << " => " << value << " = " << rate * value << std::endl;
			} catch (std::exception& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
}

bool	BitcoinExchange::parseLine(const std::string& line, std::string& date, float& value)
{
    if (std::count(line.begin(), line.end(), '|') != 1)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    std::stringstream ss(line);
    std::string rawDate, rawValue;

    std::getline(ss, rawDate, '|');
    std::getline(ss, rawValue);

    rawDate = trim(rawDate);
    rawValue = trim(rawValue);

    if (!isValidDate(rawDate))
        return false;

    if (!isValidValue(rawValue, value))
        return false;

    date = rawDate;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!isDigitsOnly(yearStr) || !isDigitsOnly(monthStr) || !isDigitsOnly(dayStr))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (year < 2009 || year > 2022)
	{
		std::cout << "Error: year out of range => " << year << std::endl;
		return false;
	}
	if (month < 1 || month > 12)
	{
		std::cout << "Error: invalid month => " << month << std::endl;
		return false;
	}
	if (day < 1 || day > 31)
	{
		std::cout << "Error: invalid day => " << day << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
	if (valueStr.empty())
	{
		std::cout << "Error: empty value" << std::endl;
		return false;
	}

	std::istringstream iss(valueStr);
	if (!(iss >> value) || !iss.eof())
	{
		std::cout << "Error: invalid value format => " << valueStr << std::endl;
		return false;
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

float	BitcoinExchange::getRateForDate(const std::string& date)
{
	std::map<std::string, float>::const_iterator it = _btcData.lower_bound(date);

	if (it != _btcData.end() && it->first == date)
		return it->second;

	if (it == _btcData.begin())
		throw std::runtime_error("no earlier date in database");

	--it;
	return it->second;
}

std::string BitcoinExchange::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}