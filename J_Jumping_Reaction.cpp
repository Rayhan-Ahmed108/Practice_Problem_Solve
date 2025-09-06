#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
const int mod = 1e9+7;

int a[N], t[N*4], pre[N];
int n, q;

void build(int node, int b, int e) {
    if (b == e) {
        t[node] = 1LL * a[e] % mod * pre[e] % mod;
        t[node] %= mod;
        return;
    }
    int mid = (b+e)/2;
    int l = node*2, r = l+1;
    build(l, b, mid);
    build(r, mid+1, e);
    t[node] = (t[l] + t[r]) % mod;
}

int query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[node];
    int mid = (b+e)/2;
    int l = node*2, r = l+1;
    return (query(l, b, mid, i, j) + query(r, mid+1, e, i, j)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<int> pre1(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pre1[i] = (pre1[i-1] + a[i]) % mod;
    }

    pre[n] = 0;
    for (int i=n-1; i>=1; i--) {
        pre[i] = (pre[i+1] + a[i+1]) % mod;
    }

    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = query(1, 1, n, l, r);
        ans %= mod;

        int sum = ((pre1[r] - pre1[l-1]) % mod + mod) % mod;
        int need = ((pre1[n] - pre1[r]) % mod + mod) % mod;
        long long need1 = 1LL * sum * need % mod;

        cout << ((ans - need1) % mod + mod) % mod << "\n";
    }
}
