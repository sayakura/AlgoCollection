#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string mostCommonNgram(int n, string s) {
    unordered_map<string, int> cnt;
    int maxcnt = 0; 
    string ret = s;
    for (int i = 0; i < s.size() - n + 1; i++) {
        string cur = s.substr(i, n);
        if (cur.find(' ') != -1) 
            continue ;
        if (++cnt[cur] > maxcnt) {
            maxcnt = cnt[cur];
            ret = cur;
        }
    }
    return ret;
}

int main() {
    string s = "Practitioners[who?] more interested in multiple word terms might preprocess strings to remove spaces.[who?] Many simply collapse whitespace to a single space while preserving paragraph marks, because the whitespace is frequently either an element of writing style or introduces layout or presentation not required by the prediction and deduction methodology. Punctuation is also commonly reduced or removed by preprocessing and is frequently used to trigger functionality. n-grams can also be used for sequences of words or almost any type of data. For example, they have been used for extracting features for clustering large sets of satellite earth images and for determining what part of the Earth a particular image came from.[5] They have also been very successful as the first pass in genetic sequence search and in the identification of the species from which short sequences of DNA originated";
    cout << mostCommonNgram(3, s) << endl;
}
