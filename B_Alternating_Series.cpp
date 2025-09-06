#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        if (a[0] != b[0] || a[n-1] != b[n-1]) {
            cout << "NO\n";
            continue;
        }

        vector<int> diff_a, diff_b;
        for (int i = 0; i < n-1; i++) {
            diff_a.push_back(a[i] ^ a[i+1]);
            diff_b.push_back(b[i] ^ b[i+1]);
        }

        sort(diff_a.begin(), diff_a.end());
        sort(diff_b.begin(), diff_b.end());

        if (diff_a == diff_b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}