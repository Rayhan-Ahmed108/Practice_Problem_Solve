// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);

const int M = 127657753;
const int MAX_N = 1e6 + 9;

struct mint {
    int x;
    mint(int x = 0) : x((x % M + M) % M) {}
    mint& operator+=(const mint& a) { x += a.x; if (x >= M) x -= M; return *this; }
    mint& operator-=(const mint& a) { x -= a.x; if (x < 0) x += M; return *this; }
    mint& operator*=(const mint& a) { x = (int64_t)x * a.x % M; return *this; }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }

    mint operator+(const mint& a) const { return mint(*this) += a; }
    mint operator-(const mint& a) const { return mint(*this) -= a; }
    mint operator*(const mint& a) const { return mint(*this) *= a; }
    mint operator/(const mint& a) const { return mint(*this) /= a; }

    mint pow(int p) const {
        mint a = *this, res = 1;
        while (p) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }

    mint inv() const {
        return pow(M - 2);
    }

    friend ostream& operator<<(ostream& os, const mint& a) {
        return os << a.x;
    }
};

vector<mint> F(MAX_N+1);

void precompute() {
    if (MAX_N >= 0) F[0] = mint(2);
    if (MAX_N >= 1) F[1] = mint(3);
    if (MAX_N >= 2) F[2] = mint(5);
    for (int i = 3; i <= MAX_N; i++) {
        mint inv_denom = F[i-3].inv();
        mint temp = F[i-1] * inv_denom;
        temp = temp - 1;
        F[i] = F[i-2] * temp;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << F[n] << "\n";
}

int32_t main() {
    FAST_IO
    precompute();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}