#include <memory>
#include <iostream>

using namespace std;

int main(){
    auto ptr1 = make_shared<int>(10);
    cout << *ptr1 << endl;
    cout << ptr1.unique() << endl;                              //离开作用域时或发生异常时,share pointer会自动释放(delete) 的内存
    cout << ptr1.use_count() << endl;
    cout << "create another smart pointer" << endl;
    shared_ptr<int> ptr2 = ptr1;
    cout << *ptr2 << endl;
    cout << ptr2.unique() << endl;
    cout << ptr2.use_count() << endl;

}