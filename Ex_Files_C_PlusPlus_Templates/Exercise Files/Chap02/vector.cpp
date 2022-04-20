// vector.cpp by Bill Weinman <http://bw.org/>
// 2019-11-03 for CppSTL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// MARK: - utility functions

//STL contains a list of conatiners
//containers share a number of common features to make them convienent and easy to use
//make common data structures available to many different types and classes

//vector one of the more common stl containers
//sequence container - holds elements in a sequenetial order


// print the elements of the vector - template function
template<typename T>
void printv(vector<T> & v) {
    if(v.empty()) return;
    for(T &i : v) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * s, const int n) { cout << s << ": " << n << endl; }

// MARK: - main

int main() {
    cout << "vector from initializer list: " << endl;
    //vector if int - initialsed using initialiser list c++ 11 onwards
    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printv(v1);
    
    // info - most containers have a common set of memeber functions for getting information
    message("size", (int) v1.size());
    message("front", v1.front()); 
    message("back", v1.back());
    
    // index - 0 indexed
    message("element at 5", v1[5]);
    message("element at 5", v1.at(5));
    
    // insert - pass an iterators - starts to the beginning and add 5 to it
    message("insert 42 at begin + 5:");
    v1.insert(v1.begin() + 5, 42);
    printv(v1);
    
    // erase - same iterator
    message("erase at begin + 5:");
    v1.erase(v1.begin() + 5);
    printv(v1);
    
    // push_back
    message("push back 47:");
    v1.push_back(47);
    printv(v1);
    
    // pop_back
    message("pop_back:");
    v1.pop_back();
    printv(v1);
    
    // empty
    message("empty:");
    vector<int> vx = { 1, 2, 3 };
    //loop through vector with empty function to pop them off untill empty
    while(!vx.empty()) {
        printv(vx);
        vx.pop_back();
    }
    
    // clear
    message("clear:");
    //vx empty with last sequence
    vx.insert(vx.begin(), { 1, 2, 3, 4, 5 });
    printv(vx);
    message("vx size", (int) vx.size());
    message("vx.clear()");
    //clear does the same as empty
    vx.clear();
    message("vx size", (int) vx.size());
    printv(vx);
    
    // constructors
    
    // from C-array
    constexpr size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    message("vector from C-array:");
    vector<int> v2(ia, ia + size);
    printv(v2);
    
    // filled with strings
    message("vector filled with string:");
    vector<string> v3(5, "string");
    printv(v3);
    
    // copy constructor - create v4 from v3
    message("vector copied from vector:");
    vector<string> v4(v3);
    printv(v4);
    
    // move constructor
    message("vector (v5) moved from vector (v4):");
    message("size of v4", (int) v4.size());
    //move constructor - moves elements from v4 to vector 5
    vector<string> v5(std::move(v4));
    printv(v5);
    message("size of v4", (int) v4.size());
    
    return 0;
}
