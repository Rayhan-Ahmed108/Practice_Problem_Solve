// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
const int INF = 1e18;

int a, b, x, y;
map<int, int> dp;

int rec(int a) {
    if (a == b) return 0;
    if (dp.count(a)) return dp[a];
    
    int res = INF;

    if ((a ^ 1) > a && (a ^ 1) <= b) {
        res = min(res, rec(a ^ 1) + y);
    }
    if (a + 1 <= b) {
        res = min(res, rec(a + 1) + x);
    }

    return dp[a] = res;
}


void sol() {
    cin >> a >> b >> x >> y;
    dp.clear();
    if (a > b) {
        if ((a ^ 1) == b) cout << y << "\n";
        else cout << -1 << "\n";
        return;
    }
    cout << rec(a) << "\n";
}
int32_t main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) sol();
}
