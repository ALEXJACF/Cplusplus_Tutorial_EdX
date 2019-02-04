#include <iostream>

using namespace std;  // no need to use std::   on functions

int main()
{
 	
 	struct coffeeBean{
     	string name;
     	string country;
     	int strength;
	};

	coffeeBean myBean = { "Strata", "Colombia", 10 };   //initializer and declarations
	coffeeBean newBean;    // init
	
	newBean.name = "Flora";           //declaration
	newBean.country = "Mexico";
	newBean.strength = 9;
	cout << "Coffee bean " + newBean.name + " is from " + newBean.country   << endl;
 	cout << "Coffee bean " + myBean.name + " is from " + myBean.country  << endl;
 	
 	
   	return 0;
}
