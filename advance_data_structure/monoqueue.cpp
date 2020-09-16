#include <deque>

using namespace std;

// we will keep the queue in an increasing order
// the front has the smallest number
deque<int> q;

// finding the minimum
int _min = q.front(); 

// add an element to the queue
void add(int element) {
    while (!q.empty() && q.back() > element) 
        q.pop_back();
    q.push_back(element);
}

void remove(int element) {
    while (!q.empty() && q.front() == element) 
        q.pop_front();
    // or simply erase it ?
}