#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility> // for std::pair
#include <unistd.h>
#include <iomanip>

double getElapsedTime(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void	printV(const std::vector<int> input)
{
	for (size_t i = 0; i < input.size(); ++i)
    std::cout << input[i] << " ";
    std::cout << std::endl;
}

void	printD(const std::deque<int> input)
{
	for (size_t i = 0; i < input.size(); ++i)
    std::cout << input[i] << " ";
    std::cout << std::endl;
}

std::string trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool	isAllDigit(const std::string& str)
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

bool	isAlreadyInV(const std::vector<int> &input, const int value)
{
	std::vector<int>::const_iterator it = input.begin();
	for (; it != input.end(); ++it)
	{
		if (value == *it)
			return true;
	}
	return false;
}

bool	isAlreadyInD(const std::deque<int> &input, const int value)
{
	std::deque<int>::const_iterator it = input.begin();
	for (; it != input.end(); ++it)
	{
		if (value == *it)
			return true;
	}
	return false;
}

bool	parseToVector(int ac, char **av, std::vector<int> &output)
{
	int value;

	for (int i = 1; i < ac; ++i)
	{
		std::string valueStr = trim(av[i]);
		if (valueStr.empty())
			return false;
		if (!isAllDigit(valueStr))
			return false;
		try{
			value = std::stoi(valueStr);
		}catch (...) {
			return false;
		}
		if (!isAlreadyInV(output, value))
			output.push_back(value);
	}
	return true;
}

bool	parseToDeque(int ac, char **av, std::deque<int> &output)
{
	int value;

	for (int i = 1; i < ac; ++i)
	{
		std::string valueStr = trim(av[i]);
		if (valueStr.empty())
			return false;
		if (!isAllDigit(valueStr))
			return false;
		try{
			value = std::stoi(valueStr);
		}catch (...) {
			return false;
		}
		if (!isAlreadyInD(output, value))
			output.push_back(value);
	}
	return true;
}


void	mergeInsertionSortV(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > pairs;
	std::vector<int>	larger;
	std::vector<int>	smaller;
	size_t	i = 0;

	while (i + 1 < input.size())
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
		i += 2;
	}

	if (i < input.size())
		smaller.push_back(input[i]);
	
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		larger.push_back(pairs[j].first);
		smaller.push_back(pairs[j].second);
	}

	std::sort(larger.begin(), larger.end());

	for(size_t k = 0; k < smaller.size(); ++k)
	{
		int value = smaller[k];
		std::vector<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), value);
		larger.insert(it, value);
	}
	input = larger;
}

void	mergeInsertionSortD(std::deque<int> &input)
{
	std::deque<std::pair<int, int> > pairs;
	std::deque<int>	larger;
	std::deque<int>	smaller;
	size_t	i = 0;

	while (i + 1 < input.size())
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
		i += 2;
	}

	if (i < input.size())
		smaller.push_back(input[i]);
	
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		larger.push_back(pairs[j].first);
		smaller.push_back(pairs[j].second);
	}

	std::sort(larger.begin(), larger.end());

	for(size_t k = 0; k < smaller.size(); ++k)
	{
		int value = smaller[k];
		std::deque<int>::iterator it = std::lower_bound(larger.begin(), larger.end(), value);
		larger.insert(it, value);
	}
	input = larger;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: ./PmergeMe [arguments...]" << std::endl;
		return 1;
	}
	
	std::vector<int> warmup;
	parseToVector(ac, av, warmup);
	mergeInsertionSortV(warmup);


	std::deque<int> warmupd;
	parseToDeque(ac, av, warmupd);
	mergeInsertionSortD(warmupd);


	std::vector<int> inputV;
	clock_t totalStartV = clock();
	if (!parseToVector(ac, av, inputV))
	{
		std::cerr << "Error" << std::endl;
		return 2;
	}

    std::cout << "Before: ";
    printV(inputV);
    mergeInsertionSortV(inputV);
	clock_t totalEndV = clock();
	double totalElapsedV = getElapsedTime(totalStartV, totalEndV);
	std::cout << "After:  ";
	printV(inputV);

	std::cout << std::endl;

	std::deque<int> inputD;
	clock_t totalStartD = clock();
    if (!parseToDeque(ac, av, inputD))
    {
		std::cerr << "Error" << std::endl;
		return 2;
	}

	std::cout << "Before: ";
    printD(inputD);
    mergeInsertionSortD(inputD);
	clock_t totalEndD = clock();
	double totalElapsedD = getElapsedTime(totalStartD, totalEndD);
	std::cout << "After:  ";
	printD(inputD);

	std::cout << "Time to process a range of " << inputV.size() << " elements with std::vector : "
	          << std::fixed << std::setprecision(5) << totalElapsedV << " us" << std::endl;
	std::cout << "Time to process a range of " << inputD.size() << " elements with std::deque  : "
	          << std::fixed << std::setprecision(5) << totalElapsedD << " us" << std::endl;


    return 0;
}
