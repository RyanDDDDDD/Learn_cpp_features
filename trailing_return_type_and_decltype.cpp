#include <iostream>

using namespace std;

float get_float(){
    return 10.00;
}

auto fun1() -> decltype(get_float()){
    // we can use declytpe in trailing return type, it can be fine to use normal return method in this case, 
    // but in generic programming, most of time we dont know the actual return type of template (function and variable)
    // we can use decltype to deduce the return type, it will be evaluated at the return expression
    auto ret = get_float();
    return ret;
}



int main(){
    auto get = fun1();

    cout << typeid(get).name() << endl;

}