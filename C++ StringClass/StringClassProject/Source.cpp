#include <iostream>
#include "string.h"

int main()
{
	// TEST

	string str = "Hello World!";
	string str2 = "People!";

	std::cout << str.GetRaw() << std::endl;

	int len = str.GetLength();

	std::cout << len << std::endl;

	std::cout << str[0] << std::endl;

	std::cout << str.Compare(str2) << " |0 = false; 1 = true." << std::endl;

	std::cout << string::Compare(str, str2) << " |0 = false; 1 = true." << std::endl;

	str2.Prepend(str);

	std::cout << str2.GetRaw() << std::endl;

	str.SetToLowerCase();

	std::cout << str.GetRaw() << std::endl;

	str.SetToUpperCase();

	std::cout << str.GetRaw() << std::endl;

	string s = "Hello";
	string ss = "lo";

	std::cout << string::FindSubString(s,ss) << " |0 = false; 1 = true." << std::endl;

	system("pause");

	return 0;
}