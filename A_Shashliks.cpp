#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y) {
        swap(a, b);
        swap(x, y);
    }
    int ans = 0;
    if(k >= a) {
        int ans1 = (k - a) / x + 1;
        ans += ans1;
        k -= ans1 * x;
    }
    if(k >= b) {
        int need = (k - b) / y + 1;
        ans += need;
        k -= y * need;
    }
    cout << ans << endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}
