	#include "stdafx.h"
    #include "Person.h"
    #include <iostream>
    
    Person::Person()
    {
    
    }
    
    Person::Person(std::string fName, std::string lName)
    {
        firstName = fName;
        lastName = lName;
    }
    
    Person::Person(std::string fName, std::string lName, int age)
    {
        firstName = fName;
        lastName = lName;
    
        age = age;
    }
    
    
    Person::~Person()
    {
    }

    void Person::SayHello
    {
        std::cout << "Hello" << std::endl;
    }		
