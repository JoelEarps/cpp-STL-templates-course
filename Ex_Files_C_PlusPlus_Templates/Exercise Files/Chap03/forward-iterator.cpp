// forward-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <forward_list>
using namespace std;
//combination of input and output iterator with a few extra bits of functionality
//defined to be efficient from beginning to end but not back to front
int main() {
    //single linked list that uses a forward iterator
    forward_list<int> fl1 = { 1, 2, 3, 4, 5 };
    forward_list<int>::iterator it1;     // forward iterator

    //trying to set the iterator to the end and then decrementing it will fail
    
    for(it1 = fl1.begin(); it1!= fl1.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    //range based for loop uses a forward iterator

    for (auto i :fl1){
        cout << i << " ";
    }

    //more flexible that input or output as you can read and write but still lacks some funcitonality
    
    return 0;
}
