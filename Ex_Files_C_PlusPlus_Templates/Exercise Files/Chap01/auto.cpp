// auto.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-02
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

//another nice use of auto with template function

//auto from return type and this will be derived from the expression of the return
template <typename lT, typename rT>
auto tf (const lT & lhs, const rT &rhs){
    return lhs + rhs;
}

// previous versions of c/c++ delcared a vraible of autmatic storage - so was rarely used
//c++11 autokeyword repurposed for type inference
int main() {
    int i = 47;
    const char * cstr = "this is a c-string";
    const string sclass = string("this is a string class string");
    
    //strongly type and type safe - PKc type c string
    auto x = "this is a c-string";
    //declare a type - derivies a type based on the type of the expression
    //so will delcare y based on the type of x - hence a c string
    decltype(x) y;
    
    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of sclass is " << typeid(sclass).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;

    //so using auto like this will declare an interator of the type s class
    //saves a lot of figuring out how to declare that

    for (auto it = sclass.begin(); it != sclass.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    //get same result as above using range based for loop
    //auto getting the tyoe of the elements of the conatiner in s class which in this case is characters
    for (auto c : sclass){
        cout << c << endl;
    }

    cout << endl;

    //this is a c++ 
    auto z = tf<string, const char *>(sclass, cstr);
    cout << "z is " << z << endl;
    cout << "Type of z is " << typeid(z).name() << endl;

    
    return 0;
}

/* output from console - different for different platforms
@"type of i is i\r\n"
@"type of cstr is PKc\r\n"
@"type of sclass is NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE\r\n"
@"type of x is PKc\r\n"
@"type of y is PKc\r\n"
*/
