#include "Array.hpp"
#include <iomanip>

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
	std::cout << "--- " << name << " ---" << std::endl;
	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << name << "[" << i << "] = " << arr[i] << std::endl;
	std::cout << std::endl;
}

int main() {
	// Int Array
	Array<int> intArr(5);
	for (size_t i = 0; i < intArr.size(); ++i)
		intArr[i] = static_cast<int>(i * 10);

	printArray(intArr, "intArr");

	// Float Array
	Array<float> floatArr(3);
	for (size_t i = 0; i < floatArr.size(); ++i)
		floatArr[i] = static_cast<float>(i) * 0.5f;

	printArray(floatArr, "floatArr");

	// String Array
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "42";

	printArray(strArr, "strArr");

	// Copy Constructor Test
	Array<std::string> copyStrArr(strArr);
	strArr[0] = "Changed";
	std::cout << "--- Copy Test (String) ---" << std::endl;
	std::cout << "Original: " << strArr[0] << std::endl;
	std::cout << "Copy    : " << copyStrArr[0] << std::endl << std::endl;

	// Assignment Operator Test
	Array<int> assignArr;
	assignArr = intArr;
	intArr[0] = 999;
	std::cout << "--- Assignment Test (Int) ---" << std::endl;
	std::cout << "Original: " << intArr[0] << std::endl;
	std::cout << "Assigned: " << assignArr[0] << std::endl << std::endl;

	// Out-of-bounds Exception Test
	std::cout << "--- Out-of-Bounds Access ---" << std::endl;
	try {
		std::cout << intArr[100] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
