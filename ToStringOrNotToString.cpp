#include <iostream>

using namespace std;  // no need to use std::   on functions

int main()
{
 	char isAString[6] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	char isNowAString[] = { "Hello"};
	string myString = "Hello!";
	std::string myNewString = "Less typing";	
	std::cout << isAString << std::endl;
	std::cout << isNowAString << std::endl;
	cout << myString ;
	cout << myNewString << endl;
   	return 0;
}
