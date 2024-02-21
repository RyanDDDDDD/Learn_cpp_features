#include <iostream>
#include <memory>

using namespace std;

std::mutex mtx;

int main() {
    // call mtx.lock() in constructor, and unlock() in destructor
    std::lock_guard<std::mutex> lk(mtx);
}