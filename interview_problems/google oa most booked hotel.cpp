#include <bits/stdc++.h> 

using namespace std;

string mostBookedHotel(vector<string> &input) {
    unordered_map<string, int> hotels;

    int maxT = 0;
    string ret = "~~";
    for (string s : input) {
        string roomN = s.substr(1, 2);
        hotels[roomN] += (s[0] == '+') ? 1 : 0;
        int t = hotels[roomN];
        if (t >= maxT) {
            if (t == maxT) ret = min(roomN, ret);
            else ret = roomN;
            maxT = t;
        }
    }
    return ret;
}

int main() {
    vector<string> input =  {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E", "+3E", "-3E", "+3E", "-1A"};
    cout << mostBookedHotel(input) << endl;
    input = {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"};
    cout << mostBookedHotel(input) << endl;
}