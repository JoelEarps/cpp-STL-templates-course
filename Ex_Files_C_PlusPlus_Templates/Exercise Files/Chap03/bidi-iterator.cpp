// bidi-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-19 for CppSTL
#include <iostream>
#include <set>
using namespace std;
//access sequence of container in any direction
int main() {
    //set container type uses bidirectional iterator
    set<int> set1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    set<int>::iterator it1;   // iterator object

    // iterate forward
    // the end memberfunction is returns an iterator that points passed the end
    //so normal for loop works forward
    for(it1 = set1.begin(); it1 != set1.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    // iterate backward
    //the begin() function does not point passed the beginning so you can't put the decrement 
    for(it1 = set1.end(); it1 != set1.begin();) {
        //put backwards decremenet in here
        cout << *--it1 << " ";
    }
    cout << endl;
    
    // range-based for loop
    for(int i : set1) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
