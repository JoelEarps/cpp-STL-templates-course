// queue.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-14 for CppSTL
#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <string>
using namespace std;
//container adapter - wrapper that uses underlying container to store its contnets
//FIFO queue that things pop onto the bakc and push out of the front
template <typename T>
void report_queue(T & q) {
    size_t sz = q.size();
    cout << "size: " << sz;
    if(sz) cout << " front: " << q.front() << " back: " << q.back();
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main()
{
    // queue from list
    message("initialize queue from list");
    //initliase a queue from a list
    list<int> l1 = {1, 2, 3, 4, 5};
    //construct a queue from the list - two paramaters for template - integer type and list of integer type
    queue<int, list<int>> q1(l1);    // constructor copies to new list
    //reports size and front and back - as queue is not a random access conatiner
    report_queue(q1);
    
    message("pop all from q1");
    //as you pop you print out the front element
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    report_queue(q1);

    //defailt unterlying conatiner for a queue is actually a deque

    
    // default queue (deque) - if you dont ask for specific underlyign conatiner
    queue<string> q2;
    message("push strings onto q2");
    for( string s : {"one", "two", "three", "four", "five"} ) {
        q2.push(s);
    }
    report_queue(q2);
    
    message("pop all from q2");
    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    report_queue(q2);
    
    return 0;
}
