#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <set>

using namespace std;

double distance(pair<int, int> &a, pair<int, int> &b) {
    double val = (pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    return sqrt(val);
}

double closest_pair(vector<pair<int, int>> &points) {
    sort(begin(points), end(points), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    double best = numeric_limits<double>::max();
    set<pair<int, int>> yBox;
    int left = 0;
    yBox.insert(points[0]);

    for (int i = 1; i < points.size(); i++) {
        while (left < i && (points[i].second - points[left].second > best))
            yBox.erase(points[left++]);
    
        for (auto it = yBox.lower_bound({ points[i].first - best, points[i].second - best });  
            it != yBox.end() && points[i].first + best >= it->first;
            it++) {
                pair<int, int> pointB = *it;
                cout << points[i].first << "," << points[i].second << " " << pointB.first << "," << pointB.second << endl;
                cout << distance(points[i], pointB) << endl;
                best = min(best, distance(points[i], pointB)); 
            }
        yBox.insert(points[i]);
    }
    return best;
}

int main () {
    vector<pair<int, int> >input = {
        {2,2}, // A
        {2,8}, // B
        {5,5}, // C
        {6,3}, // D
        {6,7}, // E
        {7,4}, // F
        {7,9}  // G
    };
    auto ret = closest_pair(input);
    cout << "anw: " << ret << endl;
    cout << endl;

    input = {
        {2,2}, // A
        {2,8}, // B
    };
    ret = closest_pair(input);
    cout << "anw: " << ret << endl;
    cout << endl;

    input = {
        {5,5}, // A
        {5,5}, // B
        {3,3}, // B
    };
    ret = closest_pair(input);
    cout << "anw: " << ret << endl;
    cout << endl;
}

