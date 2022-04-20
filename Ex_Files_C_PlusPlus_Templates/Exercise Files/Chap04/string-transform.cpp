// string-transform.cpp by Bill Weinman <http://bw.org/>
// 2018-09-25 for CppSTL
#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;

#include "title-case.h"

int main()
{
    //two stl strings
    //s1 is normal string
    //s2 is a string of the same size but filled with dots
    string s1 = "this is a string";
    cout << s1 << endl;
    
    string s2(s1.size(), '.');

    //to upper requires scope resolution
    //strings work in transformation
    //transforms a string into title case
    transform(s1.begin(), s1.end(), s2.begin(), title_case());
    
    cout << s2 << endl;

    return 0;
}
//string is a container of characters so can be transformed the same
