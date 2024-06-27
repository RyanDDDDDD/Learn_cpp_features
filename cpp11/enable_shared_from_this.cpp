#include <iostream>
#include <memory>
#include <vector>

class Widget;

std::vector<std::shared_ptr<Widget>> vec;

class Widget : public std::enable_shared_from_this<Widget> {
public:
    Widget () {
        std::cout << "construct" << std::endl;
    }

    void process () {
        vec.emplace_back (shared_from_this ());
        // vec.emplace_back (this);
    }

    ~Widget () {
        std::cout << "deconsturct" << std::endl;
    }
};

int main () {

    std::shared_ptr<Widget> ptr = std::make_shared<Widget> ();

    ptr->process ();
    ptr->process ();
}