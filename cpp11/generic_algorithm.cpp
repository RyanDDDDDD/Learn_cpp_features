#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> vec{1,5,2,3,5,3,10,6,2};
  if (find(vec.begin(),vec.end(),10) != vec.end()){
    cout << "found element" << endl;
  } else {
    cout << "not found" << endl;
  }


  // compare same number of elements as vec
  vector<int> vec1{1,5,2,3,5,3,10,6,2,1};

  bool check = equal(vec.begin(), vec.end(), vec1.begin());
  cout << check << endl;
  
}