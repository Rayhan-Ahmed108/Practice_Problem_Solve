#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int ans = n - 1; 
    for (int x = 1; x * x <= n; ++x) {
        int y = (n + x - 1) / x; 
        ans = min(ans, x - 1 + y - 1);
    }
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
