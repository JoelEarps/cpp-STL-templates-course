// lambda.cpp by Bill Weinman <http://bw.org/>
// 2018-09-24 for CppSTL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//can use a lambda function in place of the functor in trasnform
template <typename T>
void disp_v(vector<T> & v) {
    if(!v.size()) return;
    for(T e :  v) { cout << e << " "; }
    cout << endl;
}

int main()
{
    int accum = 14;
    //capturing the accum variable - takes one parameter called d and returns an int
    //it is mutable so compiler knows it is changing a value

    auto x = [accum](int d) mutable -> int { return accum += d; };
    //we can add this lambda function into the transform function
    //transform(v1.begin(), v1.end(), v2.begin(), [accum](int d) mutable -> int { return accum += d; };);
    vector<int> v1 = { 1, 2, 3, 4, 5};
    disp_v(v1);
    
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);

    disp_v(v2);
    
    return 0;
}

//lamda functions are common and a convienent way to transform