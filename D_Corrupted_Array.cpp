#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        x--;

        int left_count = 0;
        int right_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (i < x) {
                    left_count++;
                } else if (i > x) {
                    right_count++;
                }
            }
        }

        if (left_count == 0 || right_count == 0) {
            cout << 1 << '\n';
        } else {
            cout << 1 + 2 * min(left_count, right_count) << '\n';
        }
    }
    return 0;
}