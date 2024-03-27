#include <iostream>

template<typename T>
class Smart_ptr {
public:
    template<typename U>
    Smart_ptr(const Smart_ptr<U> &ptr) {
        std::cout << "normal copy constructor" << std::endl;
    }

    template<typename U>
    explicit Smart_ptr(U* ptr) {
        std::cout << "generalized template constructor" << std::endl;
    }


};

int main() {
    int* num = new int(10);

    // passing a raw pointer to initialize obj, using generalized template construtor
    Smart_ptr<int*> ptr{num};

    // passing a pointer to Smart_ptr<int*> to initialzie obj, using generalized template construtor
    Smart_ptr<int*> ptr2{&ptr};
    
    // differrent types of Smart_ptr
    long* num2 = new long(20);
    Smart_ptr<long*> ptr3{num2};

    // using copy construcor for initialization, but it caccpet differrent type of Smart_ptr
    Smart_ptr<int*> ptr4{ptr3};


    delete num;
    delete num2;
}