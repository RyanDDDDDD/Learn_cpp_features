#include <iostream>
#include <map>
#include <vector>

using namespace std;

class UnionFind{
  public:
    UnionFind(vector<int>& nums){
      for (int num : nums){
        parent.insert({num,num});
      }
    }

    int find(int num){
      if (num == parent.find(num) -> second){
        return num;
      }
      else{
        parent.find(num) -> second = find(parent.find(num) -> second);
        return parent.find(num) -> second;
      }
    }

    void merge(int num1,int num2){
      parent.find(num1) -> second = num2;
    }

    void print(){
      for (auto it = parent.begin(); it != parent.end(); it++){
        cout << it -> first << " and " << it -> second << endl;
      }
    }

  private:
    map<int, int> parent;
};

////////////////////////

int p[UINT_MAX];
int s[UINT_MAX];

int find(int num){
  if (num != p[num]) p[num] = find(p[num]);
  return p[num];
}

void merge(int num1,int num2){
 p[find(num2)] = find(num1);
}


int main(){

  vector<int> vec{1,2,3,4,5}; 
  UnionFind uf{vec};

  uf.print();
  


}