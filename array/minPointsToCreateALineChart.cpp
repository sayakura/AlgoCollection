#include <vector>
#include <iostream>

using namespace std;

double getScope (vector<double> &a, vector<double> &b) {
    double x = a.front();
    double y = a.back();

    double x2 = b.front();
    double y2 = b.back();
    return (y2 - y) / (x2 - x);
}

vector<vector<double>> minPointsToCreateALineChart(vector<vector<double>> &input) {
    vector<vector<double>> ret;

    ret.push_back(input.front());
    if (input.size() == 1)
        return ret;
    for (int i = 1; i < input.size() - 1; i++) {
        double a = getScope(input[i - 1], input[i]);
        double b = getScope(input[i], input[i + 1]);
        if (getScope(input[i - 1], input[i]) == getScope(input[i], input[i + 1]))
            continue ;
        else 
            ret.push_back(input[i]);
    }
    ret.push_back(input.back());
    return ret;
}

void print(vector<vector<double>> &res) {
    for (auto r : res) {
        cout << "[" << r.front() << "," << r.back() << "] ";
    }
    cout << endl;
}

int main() {
    vector<vector<double> > input = { {0, 0}, {1, 1}, {2, 2}, {3, 4}, {4, 6}, {5, 5}, {6, 4}, {7, 3}, {8, 3}, {9, 3}};
    auto res = minPointsToCreateALineChart(input);
    print(res);

    input = {{0, 3}, {1, 2.5}, {2, 2}, {3, 1.5}, {4, 1.5}, {5, 1}, {6, 0.5}, {7, 0}};
    res = minPointsToCreateALineChart(input);
    print(res);

    input = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    res = minPointsToCreateALineChart(input);
    print(res);


    input = {{0, 0}, {1, 4}, {2, 3}, {3, 7}, {4, 2}, {5, 5}, {6, 0}};
    res = minPointsToCreateALineChart(input);
    print(res);

    input = {{0, 2}};
    res = minPointsToCreateALineChart(input);
    print(res);
    return 0;
}