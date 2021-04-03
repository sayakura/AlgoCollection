#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct List {
    int val;
    List *next;
    List(int v) : val(v), next(nullptr) {} 
};

void set_and_union(List *l1, List *l2) {
    unordered_set<int> _union;
    unordered_set<int> _intersect;

    auto t = l1;
    while (t) {
        _union.insert(t->val);
        t = t->next;
    }
    t = l2;
    while (t) {
        if (_union.insert(t->val).second == false)
            _intersect.insert(t->val);
        t = t->next;
    }

    for (int n : _intersect)
        cout << n << " ";
    cout << endl;
    for (int n : _union)
        cout << n << " ";
    cout << endl;
}

int main () {
    auto a = {1, 3, 4, 7, 9};
    auto b = {3, 4, 12, 31, 45};
    auto dummyA = List(0);
    auto dummyB = List(0);
    auto aHead = &dummyA;
    auto bHead = &dummyB;

    for (int na : a) {
        aHead->next = new List(na);
        aHead = aHead->next;
    }
    for (int nb : b) {
        bHead->next = new List(nb);
        bHead = bHead->next;
    }
    set_and_union(dummyA.next, dummyB.next);


    a = {1, 2, 3, 4, 5};
    b = {1, 2, 2, 3, 1, 5, 4, 6};
    dummyA = List(0);
    dummyB = List(0);
    aHead = &dummyA;
    bHead = &dummyB;

    for (int na : a) {
        aHead->next = new List(na);
        aHead = aHead->next;
    }
    for (int nb : b) {
        bHead->next = new List(nb);
        bHead = bHead->next;
    }
    set_and_union(dummyA.next, dummyB.next);
}


