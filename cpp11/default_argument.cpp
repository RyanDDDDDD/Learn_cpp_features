#include <iostream>

using namespace std;

void print(int a = 10, int b = 10){
	cout << a << ' ' << b  << endl;
}

int main(){
	print();			// default arguemtn would be used
	print(20);			
}
