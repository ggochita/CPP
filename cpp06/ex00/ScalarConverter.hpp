#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static void convert(const std::string& literal);

};

void convertFromChar(char c);
void convertFromInt(int i);
void convertFromFloat(float f);
void convertFromDouble(double d);

bool	isChar(const std::string& literal);
bool	isInt(const std::string& literal);
bool	isFloat(const std::string& literal);
bool	isDouble(const std::string& literal);

void	printChar(char c);
void	printFloat(float f);
void	printDouble(double d);
void	printSpecial(const std::string& literal);

#endif