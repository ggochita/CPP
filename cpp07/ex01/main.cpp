#include "iter.hpp"

int main()
{
	int arr[] = {1, 2 ,3 ,4};
	//std::string str[] = {"helo", "welo", "mellow"};

	iter(arr, 4, replaceInt);
	iter(arr, 4, printInt);
}