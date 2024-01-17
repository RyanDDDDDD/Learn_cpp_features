#include <iostream>
#include <string>

template <typename T> class base {
    public:
    base () {
    }

    base (T t) : t_{ t } {
        std::cout << "initialize" << std::endl;
    }

    private:
    T t_;
};

template <class... Args> class derived : public base<Args>... {
    public:
    // inherit from multiple instance of base class and use their constructor to
    // initialize object
    using base<Args>::base...;
};

int main () {
    derived<int, std::string, bool, float> d1 = 11;
    d1                                        = true;
    d1                                        = std::string ("dsadas");
    d1                                        = float (123.3123);
}