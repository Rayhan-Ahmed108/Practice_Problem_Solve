#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int a[N], t[4 * N];

void built(int node, int b, int e, int level) {
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    built(l, b, mid, level - 1);
    built(r, mid + 1, e, level - 1);

    if (level % 2 == 1) {
        t[node] = t[l] | t[r];
    } else {
        t[node] = t[l] ^ t[r];
    }
}

void update(int node, int b, int e, int i, int x, int level) {
    if (i < b || i > e) return;
    if (b == e) {
        t[node] = x;
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, x, level - 1);
    update(r, mid + 1, e, i, x, level - 1);

    if (level % 2 == 1) {
        t[node] = t[l] | t[r];
    } else {
        t[node] = t[l] ^ t[r];
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int size = 1 << n;
    for (int i = 1; i <= size; ++i) {
        cin >> a[i];
    }
    built(1, 1, size, n);
    while (m--) {
        int pos, val;
        cin >> pos >> val;
        update(1, 1, size, pos, val, n);
        cout << t[1] << '\n';
    }
    return 0;
}
