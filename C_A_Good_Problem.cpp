#include <bits/stdc++.h>
using namespace std;
#define int long long

int rec(int l) {
    if (l == 0) {
        return 0;
    }
    int x = 0;
    for (int i = 62; i >= 0; i--) {
        if (l & (1LL << i)) {
            continue;
        }
        int bit = (1LL << i);
        int ans = (i == 0) ? 0 : (bit - 1);
        int al = ans & (~l);
        if ((x | al) < l) {
            x |= bit;
        }
    }
    return x;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n % 2 == 1) {
            cout << l << endl;
        } else {
            if (n == 2) {
                cout << -1 << endl;
            } else {
                int y = rec(l);
                if (y < l || y > r) {
                    cout << -1 << endl;
                } else {
                    if (k <= n - 2) {
                        cout << l << endl;
                    } else {
                        cout << y << endl;
                    }
                }
            }
        }
    }
    return 0;
}