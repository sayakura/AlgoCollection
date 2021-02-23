#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int getCount(string &s) {
    char sm = 100;
    char count = 0;
    for (char c : s) {
        if (c < sm) {
            sm = c;
            count = 1;
        } else if (c == sm)
            count++;
    }
    return count;
}

vector<int> compareString(string a, string b) {
    vector<string> A, B;
    vector<int> ret;
    unordered_map<string, int> count;

    a += " ", b += " ";
    int len = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') {
            A.push_back(a.substr(i - len, len));
            len = 0;
        } else len++;
    } 
    len = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == ' ') {
            B.push_back(b.substr(i - len, len));
            len = 0;
        } else len++;
    }

    for (int j = 0; j < B.size(); j++) {
        if (count.find(B[j]) == count.end())
            count[B[j]] = getCount(B[j]);
        int c = count[B[j]];
        int cnt = 0;
        // bsearch works here 
        for (int i = 0; i < A.size(); i++) {
            if (count.find(A[i]) == count.end())
                count[A[i]] = getCount(A[i]);
            if (count[A[i]] < c) cnt++;
        }
        ret.push_back(cnt);
    }
    return ret;
}


int main() {
    string a = "abcd aabc bd";
    string b = "aaa aa";
    auto r = compareString(a, b);
    for (int n : r) 
        cout << n << " ";
    cout << endl;
}