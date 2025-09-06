#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, int> cnt;
    int ans = 0;

    for(int j = 1; j <= n; j++) {
        int need = j - a[j];
        if(cnt.count(need)) ans += cnt[need];
        cnt[j + a[j]]++;
    }
    cout << ans << endl;
}
int32_t main() {
    sol();
}
