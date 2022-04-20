// input-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <iterator>
using namespace std;
//simplest form of interator - used to read values of a conatiner once and then incrementing
//values can only be read (not written) - and this can only happen one time
//iostream uses an input iterators for cin
void message(const char * m) { cout << m << endl; }

int main() {
    double d1 = 0, d2 = 0;
    
    cout << "Two numeric values: " << flush;
    cin.clear();
    //eos stream
    istream_iterator<double> eos;         // default constructor is end-of-stream
    istream_iterator<double> iit(cin);    // stdin iterator

    if(iit == eos) {
        message("no values");
        return 0;
    } else {
        d1 = *iit++;
    }
    
    if(iit == eos) {
        message("no second value");
        return 0;
    } else {
        d2 = *iit;
    }

    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;

    return 0;
}
