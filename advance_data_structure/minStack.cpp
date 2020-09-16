#include <stack>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

stack <pii> st;
void push(stack<pii> &st, int el) {
    int newmin = el;
    if (!st.empty()) 
        newmin = min(newmin, st.top().second);
    st.push({ el, newmin });
} 

int pop(stack<pii> &st) {
    int removed_element = st.top().first;
    st.pop();
    return removed_element;
}

int main() {
    vector<int> arr = { 3, 5, 2, 6, 1, 9 };
    for (int n : arr)
        push(st, n);
    while (!st.empty()) {
        cout << "top: " << st.top().first << " ";
        cout << "min: " << st.top().second << endl;
        pop(st) ;
    }
}


