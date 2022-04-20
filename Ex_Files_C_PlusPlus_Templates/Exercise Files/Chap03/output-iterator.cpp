// output-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <iterator>
using namespace std;
//compilment of inoput iterator
//write a value once and then increment
//used just like a pointer
int main()
{
    //for example cout 
    ostream_iterator<int> output(cout, " ");
    
    for(int i : { 3, 197, 42 }) {
        *output++ = i;
    }
    cout << endl;

    return 0;
}
