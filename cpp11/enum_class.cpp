#include <iostream>

using namespace std;
//https://coders-corner.net/2017/08/13/scoped-vs-unscoped-enum/
enum class color {
  red,
  blue,
  yellow
};

int main(){
    // enum class can prevent implicit type conversion 
    // and name clash when using duplicate member in different normal enum
    int myColor = static_cast<int>(color::blue);

    cout << myColor << endl;

}