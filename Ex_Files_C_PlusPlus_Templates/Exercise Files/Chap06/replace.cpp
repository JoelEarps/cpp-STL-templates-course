// replace.cpp by Bill Weinman <http://bw.org/>
// 2018-09-30 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool is_even(const T & n) {
    return ((n % 2) == 0);
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    // prime numbers < 100
    //not const save function as they do make changes in the container

    vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    disp_v(v1);
    //element to search for and element to replace it with
    replace(v1.begin(), v1.end(), 47, 99);
    disp_v(v1);

    //replace if works with a uniary predicate function - so is even
    //remove functions if elements match a search parameter - returns an iterator check to see if the end
    //then you resize()
    //check for unique and remove them

    return 0;
}
