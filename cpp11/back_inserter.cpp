#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    
    // Use back_inserter to append the elements of v2 to v1
    // back_inserter will ask container to allocate (if necessary) large memory, then return a iterator to insert element
    // which can be more eiffcient compares with using for-loop and push_back to append elemnts, because container may need 
    // to reallocate and move each element to a new memory address
    
    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));
    
    // Print the elements of v1
    for (auto i : v1) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
