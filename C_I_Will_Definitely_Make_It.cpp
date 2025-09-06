#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(3)); // 2D vector with 3 columns

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[2] < y[2];  
    });

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
