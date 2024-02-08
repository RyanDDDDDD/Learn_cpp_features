#include <iostream>

using namespace std;


/* 
1. initialize a default value in static area
*/ 
static int num = 10;
// initialize variable in static area, before running main function 
// if no initialzed value is provided, initialize it with a default value

/* 
2. indicate the function exists only in the file it is defined, to prevent namespace pollution
*/
static void func1(){
  cout << "hello world" << endl;
}

/*
3. decorate class member variable, all variable with same classes share the same static member
*/ 
class A{
  public:
    A(){
      mem_1++;
      cout << mem_1 << endl;
    }
  private:
    static int mem_1;
};

int A::mem_1 = 0;

/*
4. decorate class member function, indicate the function can be accessed without initializing the class
*/ 
class B{
  public:
    // this pointer doest exists in static member function
    static void func1(){
      cout << "hello world" << endl;
    }
};

int main(){
  cout << num << endl;
  B::func1();
  A first{};
  A second{};
  A third{};
}