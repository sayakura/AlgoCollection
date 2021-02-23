#include <iostream>
#include <vector>
using namespace std;


int kmp(const string &T, const string &P) {
  if (P.empty()) return 0;

  vector<int> pi(P.size() + 1, 0);
  for (int i = 1, k = 0; i < P.size(); ++i) {
    while (k && P[k] != P[i]) 
        k = pi[k - 1];
    if (P[k] == P[i]) 
        ++k;
    pi[i] = k;
  }
  for (int n : pi)
    cout << n << " ";
cout << endl;

  for (int i = 0, k = 0; i < T.size(); ++i) {
    while (k && P[k] != T[i]) 
        k = pi[k - 1];
    if (P[k] == T[i]) 
        ++k;
    if (k == P.size())
        return i - k + 1;
  }

  return -1;
}

int main() {
    string s = "aaaaabcaa";
    kmp(s, s);
}