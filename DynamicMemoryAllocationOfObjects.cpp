#include <iostream>
using namespace std;

class Test {
  private:
    int i;
  public:
    Test(int);
    ~Test();
    void print();
};

Test::Test(int ii) { i = ii; }
Test::~Test() { i=0; cout << "deconstructor called...value of i= " << i << endl; }
void Test::print() { cout << "value of i= " << i << endl; }

int main()
{
  Test a(10),*b,**c= new Test*[2];
  //a.print(); // this works

  b = new Test(12);
  //b->print(); // this works as well

  for (int i=0; i<2; i++)
    c[i] = new Test(i);

  //c->print(); /* this shows that the value of i=1 .. should be 0? */
  c[0]->print(); /* as expected (I guess), this prints i=1 as well... [expected because c->print() shows i=1 also */
  c[1]->print(); /* shows value of i=0... */

  delete []c; /* this fails miserably, but `delete c` works, why :( */

}
