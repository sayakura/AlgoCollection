#include <iostream>

using namespace std;

int main() {
    int n = 100;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) 
            cout << i << ", " << j << endl;
    }
    return 0;
}