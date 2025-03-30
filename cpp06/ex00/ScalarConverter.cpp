#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf" ||
		literal == "+inf" || literal == "+inff" ||
		literal == "-inf" || literal == "-inff")
	{
		printSpecial(literal);
		return ;
	}

	if (isChar(literal))
		convertFromChar(literal[0]);
	else if (isInt(literal))
		convertFromInt(std::atoi(literal.c_str()));
	else if (isFloat(literal))
		convertFromFloat(std::strtof(literal.c_str(), NULL));
	else if (isDouble(literal))
		convertFromDouble(std::strtod(literal.c_str(), NULL));
	else
		std::cout << "Unknown literal format" << std::endl;
}

bool isChar(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool isInt(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	if (i == literal.length())
		return false;

	for(; i < literal.length(); i++)
		if (!std::isdigit(literal[i]))
			return false;
	return true;
}

bool isFloat(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	for(; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else if (literal[i] == 'f' && i == literal.length() - 1)
			return hasDot && hasDigit;
		else
			return false;
	}
	return false;
}

bool isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	for(; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	return hasDot && hasDigit;
}

void	convertFromChar(char c)
{
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(c);
	std::cout << "int : " << i << std::endl;
	printFloat(f);
	printDouble(d);
}

void	convertFromInt(int i)
{
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(c);
	std::cout << "int : " << i << std::endl;
	printFloat(f);
	printDouble(d);

}

void	convertFromFloat(float f)
{
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(c);
	std::cout << "int : " << i << std::endl;
	printFloat(f);
	printDouble(d);
}

void	convertFromDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(c);
	std::cout << "int : " << i << std::endl;
	printFloat(f);
	printDouble(d);
}

void printChar(char c)
{
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	printFloat(float f)
{
	std::cout << "float: ";
	if (f == static_cast<int>(f))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << f << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed); // Reset formatting
}

void printDouble(double d)
{
	std::cout << "double: ";
	if (d == static_cast<int>(d))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << d << std::endl;
	std::cout.unsetf(std::ios::fixed); // Reset formatting
}

void	printSpecial(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal << std::endl;
}