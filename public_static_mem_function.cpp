#include <iostream>

using namespace std;

class scaler
{
public:
    static void get_no_of_topics()
    {
        // static member function can only access static member
        // if this static function is declared as private, it can only be used inside the class member function
        // and it is also only allowed to access static member or the arguments we passed in
        cout << "The number of topics already assigned:"
             << number++ << endl;
    }

private:
    static int number;
};
int scaler::number = 0;

int main()
{
    scaler S; // object of class scaler

    S.get_no_of_topics();

    scaler::get_no_of_topics();
    // two ways to invoke public static member function

    return 0;
}
