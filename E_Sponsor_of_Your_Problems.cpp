#include <bits/stdc++.h>
using namespace std;

string L, R;
int dp[20][2][2][20][20];

int go(int pos, bool tightL, bool tightR, int matchL, int matchR) {
    if (pos == L.size()) return matchL + matchR;
    
    int &res = dp[pos][tightL][tightR][matchL][matchR];
    if (res != -1) return res;

    res = INT_MAX;
    int lo = tightL ? (L[pos] - '0') : 0;
    int hi = tightR ? (R[pos] - '0') : 9;

    for (int d = lo; d <= hi; ++d) {
        bool a = tightL && (d == lo);
        bool b = tightR && (d == hi);
        int c = matchL + (d == (L[pos] - '0'));
        int d1 = matchR + (d == (R[pos] - '0'));
        res = min(res, go(pos + 1, a, b, c, d1));
    }
    return res;
}

int solve(string l, string r) {
    L = l;
    R = r;
    memset(dp, -1, sizeof(dp));
    return go(0, 1, 1, 0, 0);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
    string l, r;
    cin >> l >> r;
    cout << solve(l, r) << '\n';
    }
    return 0;
}
