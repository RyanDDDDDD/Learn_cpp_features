#include <iostream>

using namespace std;


enum color {
    red,green,yellow
};

enum class color2{
    // enum class do not allow implicit conversion
    red,green,yellow
};

int main(){

    cout << color::red << endl;
    cout << color::green << endl;
    cout << color::yellow << endl;

    cout << "==================" << endl;

    cout << static_cast<int>(color2::red) << endl;
    cout << static_cast<int>(color2::green) << endl;
    cout << static_cast<int>(color2::yellow) << endl;

    return 0;
}

