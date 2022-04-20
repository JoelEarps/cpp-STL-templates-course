// iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <vector>
using namespace std;
//stl object that can interate through the objects of a container
//works a lot like a pointer
int main() {
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    //initialised using scoper delcarator
    //bound to a type
    vector<int>::iterator it1;   // iterator object
    //begin and end are member functions
    vector<int>::iterator ibegin = vi1.begin();
    //auto can be used
    vector<int>::iterator iend = vi1.end();
    
    for(it1 = ibegin; it1 < iend; ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;
    //iterators come in different types - 5 - input, output, forward, bidirectional and random access
    //types are not exclusive and they may have  properties of more than one type 
    return 0;
}
