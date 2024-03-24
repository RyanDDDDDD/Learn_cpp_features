#include <iostream>
#include <vector>

template <typename T> class TClass {
    // There is no difference between using class and typename to specify parameter
    public:
    TClass (const T& obj) {
        mem = obj;
    }

    void print2nd (size_t i) {
        if (mem.size () < 1)
            return;

        std::cout << mem[i] << std::endl;
    }

    void iterPrint2nd (size_t i) {
        if (mem.size () < 1)
            return;

        // compiler always assume any value derived from template member is a
        // member/value, not class/type the following code would not pass
        // compilation T::const_iterator iter = mem.begin ();

        // here "const_iterator" is a nested reference type name, which rely on the type of T,
        // to tell compiler about the truth, use "typename before the declaration"
        typename T::const_iterator iter = mem.begin ();
        ++iter;

        std::cout << *iter << std::endl;
    }

    private:
    T mem;
};


int main () {
    std::vector<int> vec;
    TClass<std::vector<int>> tVec (vec);
}