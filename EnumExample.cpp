#include <iostream>

using namespace std;  // no need to use std::   on functions

int main(){
 	
 	enum Day { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
	Day payDay;
	payDay = Thursday;
	cout << payDay << endl;
	
   	return 0;
}
