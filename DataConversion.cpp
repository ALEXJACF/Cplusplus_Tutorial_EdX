#include <iostream>

 int main()
 {
 	
	double i{3.0/2}; // 1.5
	i= static_cast<int>(i);  //conversion from double to int 
   std::cout << "Result->"<< i << std::endl;
   return 0;
}
