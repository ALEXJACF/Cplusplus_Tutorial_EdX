#include <iostream>
#include <string>
using namespace std;  // no need to use std::   on functions

void PassByValue(int a){
	cout << "Inside PassByValue" << endl;
	a+=10;
	cout <<"new value: "<<a<<endl;
}
void PassByRef(int &a){
	cout << "Inside PassByRef" << endl;
	a=50;
	cout <<"new value: "<<a<<endl;
}





class Person{
	private:
	    string name;
	    int age;
	    double height, weight;
	public:
		
		string getName(){return(this->name);}
		int getAge(){return(this->age);}
		double getPeso(){return (this->weight);}
		double getAltura(){return (this->height);}
		void setName(string nome){this->name=nome;}
		void setAge(int idd){this->age=idd;}
		void setPeso(double peso){this->weight=peso;}
		void setAltura(double altura){this->height=altura;}
		void print(){cout<<"Nome: "<<name<<endl<<"Idade: "<<age<<endl<<"Peso: "<<weight<<endl<<"Altura: "<<height<<endl;}
};

void modifyPerson(Person &a){
	a.setName("teste");
	//a.print();
}

int main()
{
	/*
 	int num1=3;
 	int *pNum= new int;
 	double *pDouble= new double;
 	*pNum=5;
 	*pDouble=5.0;
 	
 	PassByValue(num1);
 	cout <<"value of num1: "<<num1<<endl;
 	
 	PassByRef(*pNum);
 	cout <<"value of pNum: "<<*pNum<<endl;
 	
 	PassByValue(*pNum);
 	cout <<"value of pNum after PassByValue: "<<*pNum<<endl;
 	
 	cout <<"value of pDouble: "<<*pDouble<<endl;
 	
 	delete pDouble;
 	
 	cout <<"value of pDouble: "<<*pDouble<<endl;
 	*/
 	
 	Person a;
 	a.setName("alex");
 	a.setAge(28);
 	a.setPeso(80.0);
 	a.setAltura(190.0);
 	
 	a.print();
 	
 	modifyPerson(a);
 	
	a.print();
	
   	return 0;
}
