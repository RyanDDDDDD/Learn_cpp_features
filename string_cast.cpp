#include <iostream>
#include <string>

using namespace std;

class A{
    public:
        A() = default;

        explicit operator std::string() const{
            std::string ret = to_string(mem_1);
            ret += " ";
            ret += to_string(mem_2);
            return ret;
        }
    private:
        int mem_1 = 10;
        int mem_2 = 20;
};

int main(){
    A obj;

    string str = static_cast<std::string>(obj);
    cout << str << endl;
}
