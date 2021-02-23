#include <vector> 
#include <iostream>
#include <unordered_map>

using namespace std;

string strtok(string &s, string &delim) {
    static unordered_map<string *, pair<int, vector<int>> > um; 
    vector<int> Pi(delim.size(), 0);
    int i = 0;
    if (um.find(&s) != um.end()) {
        i = um[&s].first;
        Pi = um[&s].second;
    }
    int beg = i;
    if (beg == s.size()) {
        um.erase(&s);
        return "";
    }
    for (int k = 0, j = 1; j < delim.size(); ++j) {
        while (k && delim[j] != delim[k])
            k = Pi[k - 1];
        if (delim[j] == delim[k])
            k++;
        Pi[j] = k;
    }
    for (int k = 0; i < s.size(); ++i) {
        while (k && delim[k] != s[i])
            k = Pi[k - 1];
        if (delim[k] == s[i])
            k++;
        // "sssssdelimsssss"
        //            |i
        //  |beg
        if (k == delim.size()) {
            string res = s.substr(beg, i - k - beg + 1);
            if (res.size() == 0) {
                k = 0;
                beg = i + 1;
                continue ;
            }
            um[&s] = { i + 1, Pi };
            return res;
        }
    }
    um[&s] = { s.size(), Pi };
    return s.substr(beg, i - beg + 1);
}


int main() {
    string s = "cnm--cmn--cmncmncn-cnmcnm--cmncmncmn----cmnmn";
    string delim = "--";
    string token = "";
    while ((token = strtok(s, delim)) != "") {
        cout << token << endl;
    }
    string s2 = "adas ads adasd asad asdas assad as      ";
    delim = " ";
    token = "";
    while ((token = strtok(s2, delim)) != "") {
        cout << token << endl;
    }
    string s3  = "我草泥马🤡我草泥马🤡我草泥马🤡我草泥马🤡我草泥马🤡我草泥马🤡";
    delim = "🤡";
    token = "";
    while ((token = strtok(s3, delim)) != "") {
        cout << token << endl;
    }
    return 0;
}