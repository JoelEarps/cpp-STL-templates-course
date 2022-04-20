// partition.cpp by Bill Weinman <http://bw.org/>
// 2018-10-01 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool is_even_tens(T & n) {
    if(n < 10) return false;
    return ((n / 10) % 2) == 0;
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

//rearrange a container to components who match conditions to the start
int main() {
    // prime numbers > 10 & < 100
    vector<int> v1 = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    disp_v(v1);

    size_t cz = count_if(v1.begin(), v1.end(), is_even_tens<int>);
    vector<int> v2(cz), v3 (v1.size()- cz);
    //stabel partion leaves the element in order
    //partition_copy
    //partition(v1.begin(), v1.end(), is_even_tens<int>);
    //element start, element end, container for elemenets that match and one for those that don't then predecate function
    partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin(), is_even_tens<int>);
    disp_v(v1);
    disp_v(v2);
    disp_v(v3);

    return 0;
}
