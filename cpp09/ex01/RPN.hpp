#pragma once

#include <string>
#include <sstream>
#include <stack>
#include <iostream>

class RPN
{
private:
	std::stack<int>	_rpnStack;
	int				_result;
	bool			_ok;
public:
	RPN();
	~RPN();

	void		getResult(const std::string& str);
private:
	void		calcResult(const std::string& str);
	void		err(void);
	bool		isSign(const std::string& str);
	bool		isAllDigit(const std::string& str);
	std::string trim(const std::string& str);
	bool		doOperation(const std::string& sign, int &opToPush);
};

RPN::RPN()
{
	_ok = false;
}

RPN::~RPN()
{
}

void	RPN::err(void)
{
	_ok = false;
	_result = -1;
}

bool	RPN::isSign(const std::string& str)
{
	if (str == "+" || str == "-")
		return true;
	if (str == "*" || str == "/")
		return true;
	return false;
}

bool	RPN::doOperation(const std::string& sign, int &opToPush)
{
	int b = _rpnStack.top();
	_rpnStack.pop();
	int a = _rpnStack.top();
	_rpnStack.pop();

	if (sign == "+")
	{
		opToPush = a + b;
		return true;
	}
	if (sign == "-")
	{
		opToPush = a - b;
		return true;
	}
	if (sign == "*")
	{
		opToPush = a * b;
		return true;
	}
	if (sign == "/")
	{
		if (b == 0)
			return false;
		opToPush = a / b;
		return true;
	}
	return false;
}

bool	RPN::isAllDigit(const std::string& str)
{
	size_t i = 0;

	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

std::string RPN::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

void	RPN::calcResult(const std::string& str)
{
	std::istringstream	ss(str);
	std::string			valueStr;
	int					opToPush;

	while (!_rpnStack.empty()) _rpnStack.pop();

	while (std::getline(ss, valueStr, ' '))
	{
		valueStr = trim(valueStr);
		if (valueStr.empty())
			return err();
		if (!isAllDigit(valueStr))
		{
			if (isSign(valueStr) && _rpnStack.size() > 1)
			{
				if (!doOperation(valueStr, opToPush))
					return err();
				_rpnStack.push(opToPush);
			}
			else
				return err();
		}
		else
		{
			int n = std::stoi(valueStr);
			if (n > 9)
				return err();
			_rpnStack.push(n);
		}
	}

	if (_rpnStack.size() != 1)
		return err();
	_result = _rpnStack.top();
	_ok = true;
}

void		RPN::getResult(const std::string& str)
{
	calcResult(str);
	if (_ok)
		std::cout << _result << std::endl;
	else
		std::cerr << "Error" << std::endl;
}