// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//a template is a compiler extraction that allows you to write to generic code that applies to various types and classes without concern for
// the specific type 

//a template function - when called, a specialisation is created
// this one is called max of - it doesnt care about the type and at the moment neither do we we want to know about the logic of the function
//arguements a and b of type const t

//typename and class are interchangable - just be consistent
//typename T is an alias that will be replaced by a type at the time of the call ( the template paramaters)
//this is a compiler abstraction and creates a speciailisation of the function for the type at compile time
template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}

template <typename T>
void print_v(const vector<T> &v){
    if (v.empty()) return;
    for (const T & i : v) cout << i << " ";
    cout << endl;
}

int main() {
    /*
    int a = 7;
    int b = 9;
    //so we pass the function of type int and the vairables a and b
    //specialisation of int in place of t
    //therefore it will make a function of int maxof(const int &a, const int &b {}) 
    //so compiler does this at compile time
    cout << "max is " << maxof<int>( a, b ) << endl;
 */
    //so lets change the type
    //so here if we past char * - we are comparing the pointer value not the actual value of seven and nine - as seven is bigger than nine in asci
    //so not string comparison
    // so change to string
    /*
    const char * a = "seven";
    const char * b = "nine";
    
    cout << "max is " << maxof<const char *>( a, b ) << endl; 
    */

    //so strings know abotu string comparisons
    string a = "seven";
    string b = "nine";
    
    //specilisation is a copy of the function, is inviisble to the programmer at compile time
    cout << "max is " << maxof<string>( a, b ) << endl;

    //specialisation - is blessing and curse
    //ensure the templates are type safe but also imposes overhead at compile time and run time + add size to object file

    //compiler is able to deduce the type from the context 
    //so lets do it with vectors
    //will workj the same if you delcare it as a vector of strings

    vector<int> v1 = { 1, 2, 3, 4, 5};
 
    print_v(v1);

    return 0;
}


