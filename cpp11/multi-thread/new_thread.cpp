#include <thread>
#include <iostream>

using namespace std;

void hello(){ 
    std::cout << "Hello Concurrent World" << std::endl; 
}

int main(){
    std::thread t(hello);
    std::thread t1(hello);
    t.join();
    t1.join();
    
    // wait of thread to finish its execution

}