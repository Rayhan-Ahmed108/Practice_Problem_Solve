#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], t[N*4];

void built(int node, int b, int e) {
    if(b == e) {
        t[node] = a[e];
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    built(l, b, mid);
    built(r, mid + 1, e);
    t[node] = __gcd(t[l], t[r]);
}
int query(int node, int b, int e, int i, int j) {
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) {
        return t[node];
    }
    int l = 2 * node, r = l + 1;
    int mid  = (b + e) / 2;
    return __gcd(query(l, b, mid, i, j) , query(r, mid + 1, e, i, j));
}
int main() {
int t;
cin >> t;
while(t--) {
int n, ans = 0;
cin >> n;
for(int i = 1; i <= n; i++) {
    cin >> a[i];
}
sort(a + 1, a + n + 1);
built(1, 1, n);
for(int i = 1; i <= n; i++) {
    int need = i + 1;
    need /= 2;
    int ans = query(1, 1, n, need, (n - i/2));
    cout << ans << ' ';
}
cout << endl;
}

}