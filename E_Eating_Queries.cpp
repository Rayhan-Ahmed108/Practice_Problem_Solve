// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define vi vector<int>
#define endl "\n"

const int mod = 1e9 + 7;

void sol() {
    int n, m;
    cin >> n >> m;

    vi v(n + 1), pre(n + 1), pre1(n + 1);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    vi v1 = v;
    sort(v1.begin() + 1, v1.end());
    pre1[1] = v1[1];
    for (int i = 2; i <= n; i++) {
        pre1[i] = pre1[i - 1] + v1[i];
    }
    vi v2 = v;
    sort(v2.begin() + 1, v2.end(), greater<int>());
    pre[1] = v2[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + v2[i];
    }

    while (m--) {
        int k;
        cin >> k;

        if (k > sum) {
            cout << -1 << endl;
        } else if (k <= pre[1]) {
            cout << 1 << endl;
        } else {
            int ans = -1;
            auto it = lower_bound(pre.begin() + 1, pre.begin() + n + 1, k);
            if (it != pre.begin() + n + 1) {
                ans = it - pre.begin();
            }

            cout << ans << endl;
        }
    }
}

int32_t main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) sol();
}
