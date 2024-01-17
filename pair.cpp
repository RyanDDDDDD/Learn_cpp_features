#include <utility>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
  pair<int,int> pa{1,2};

  vector<pair<int,int>> vec{pa};

  map<int,int> mp{};

  while ( vec.size() != 10 ) {
    pair<int,int>pa = make_pair<int,int>(vec.size() + 1, vec.size() + 2); 
    vec.emplace_back(pa);
    mp[pa.first] = pa.second;
  }

  cout << "size of vec = "  << vec.size() << endl;
  
  for (const auto &pa : mp){
    cout << pa.first << ' ' << pa.second << endl;
  }

  if (mp.erase(2)) {
    cout << "remove successfully" << endl;
  } else {
    cout << "remove failed" << endl;
  }

}