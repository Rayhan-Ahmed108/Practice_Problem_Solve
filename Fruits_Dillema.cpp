#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], t[N * 4];
int n, m;

void build(int node, int b, int e) {
    if (b == e) {
        if (a[e] % m == 0)
            t[node] = 1;
        else
            t[node] = 0;
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = t[l] + t[r];
}

int query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[node];
    int l = 2 * node, r = l + 1;
    int mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
int main() {
    cin >> n >> m;
    map<int, int> mp1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp1[x]++;
        a[i] = mp1[x];
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    cout << endl;
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }
}
