// set.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-03 for CppSTL
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
//container of a sorted set of elements
//set class holds only unique elements whereas multi set class contains multiple unique ones
// print the elements of the set
template<typename T>
void print_set(T & s) {
    if(s.empty()) return;
    for(auto x : s) cout << x << " ";
    cout << endl;
}

// print a simple message
void message(const char * m) { cout << m << endl; }
template <typename T>
void message(const char * m, const T & v) { cout << m << ": " << v << endl; }

int main() {
    message("construct set set1");
    //multiset<string>
    set<string> set1 = { "one", "two", "three", "four", "five" };
    message("size of set", set1.size());
    message("ordered set is alphabetical");
    print_set(set1);
    
    message("insert element six");
    set1.insert("six");
    print_set(set1);
    
    //find pass an iterator
    message("find and erase element six");
    set<string>::iterator it = set1.find("six");
    if(it != set1.end()) {
        message("erasing", *it);
        set1.erase(it);
    } else {
        cout << "not found" << endl;
    }
    print_set(set1);
    
    //this doesn't work - check for failure by checking return value
    message("inserting duplicate element five");
    auto r = set1.insert("five");
    //r will be a pair - the value that was attemoted ot be entered and then true or false 
    if (!r.second) message("insert failed");
    print_set(set1);
    cout << endl;
    
    
    message("construct unordered set set1");
    //unordered multiset
    unordered_set<string> set2 = { "one", "two", "three", "four", "five" };
    message("size of set", set2.size());
    message("unordered set has no defined order");
    print_set(set2);
    
    message("insert element six");
    set2.insert("six");
    print_set(set2);
    
    message("find and erase element six");
    auto it2 = set2.find("six");
    if(it2 != set2.end()) {
        message("erasing", *it2);
        set2.erase(it2);
    } else {
        cout << "not found" << endl;
    }
    print_set(set2);
    
    message("inserting duplicate element five");
    set2.insert("five");
    print_set(set2);
    cout << endl;
    
    return 0;
}

//unordered sets hwere you need hash searches