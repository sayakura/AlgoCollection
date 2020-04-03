#include <vector>
#include <utility>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

float gmin;
vector<pair<int, int>> answer;

float getDistance(pair<int, int> &p1, pair<int, int> &p2) {
    double x = p1.first - p2.first; //calculating number to square in next step
	double y = p1.second - p2.second;
	double dist;
	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  
	return dist;
}

float bruteForce(vector<pair<int, int>> &points, int n) {  
  float mindist = numeric_limits<float>::max();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      float d = getDistance(points[i], points[j]);
      if (d < mindist) {
        mindist = d;
        if (d <= gmin) {
            gmin = d;
            answer = { points[i], points[j] };
        }
      }
    }
  }
  return mindist;
}

float stripClosest(vector<pair<int, int>> strip, int n, float d) {
    float min = d;
    sort(strip.begin(), strip.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second < rhs.second;
    });
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n && (strip[j].second - strip[i].second) < min; j++) 
            if (getDistance(strip[i], strip[j]) < min) {
                min = getDistance(strip[i], strip[j]);
                if (min < gmin) {
                    gmin = min;
                    answer = { strip[i], strip[j] };
                }
            }
    return min;
}

float closestUtil(vector<pair<int, int> > &pointX, int n) {
    if (n <= 3)
        return bruteForce(pointX, n);
    int mid = n / 2;
    pair<int, int> midPoint = pointX[mid];

    float dl = closestUtil(pointX, mid);
    vector<pair<int, int> > pointXr(pointX.begin() + mid, pointX.end());
    float dr = closestUtil(pointXr, n - mid);
    float d = min(dl, dr);

    vector<pair<int, int>> strip;
    for (int i = 0; i < n; i++) 
        if (abs(pointX[i].first - midPoint.first) < d) 
            strip.push_back(pointX[i]);
    return min(d, stripClosest(strip, strip.size(), d));
}

vector< pair<int, int>> closestPair(vector<pair<int, int>>points) {
    vector<pair<int, int> > pointX(points);
    gmin = numeric_limits<float>::max();
    answer = {{}, {}};
    sort(pointX.begin(), pointX.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.first < rhs.second;
    });
    closestUtil(pointX, pointX.size());
    return answer;
}

int main() {

    vector<pair<int, int> >input = {
        {2,2}, // A
        {2,8}, // B
        {5,5}, // C
        {6,3}, // D
        {6,7}, // E
        {7,4}, // F
        {7,9}  // G
    };
    auto anw = closestPair(input);
    for (auto x: anw) 
        cout << x.first << "  " << x.second << endl;

    cout << "=====" << endl;

    input = {
        {2,2}, // A
        {2,8}, // B
    };
    anw = closestPair(input);
    for (auto x: anw) 
        cout << x.first << "  " << x.second << endl;

    cout << "=====" << endl;

    input = {
        {2,2}, // A
        {2,8}, // B
        {5,5}, // C
        {5,5}, // C
        {6,3}, // D
        {6,7}, // E
        {7,4}, // F
        {7,9}  // G
    };
    anw = closestPair(input);
    for (auto x: anw) 
        cout << x.first << "  " << x.second << endl;
    return 0;
}