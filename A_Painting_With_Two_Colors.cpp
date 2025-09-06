#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll g = 0;
        for (ll x : a) {
            g = gcd(g, x);
        }
        if (g > 1) {
            for (ll x : a) {
                cout << x << " ";
            }
            cout << "\n";
            continue;
        }
        int d = 2;
        for (int p : primes) {
            if (k % p != 0) {
                d = p;
                break;
            }
        }
        ll inv_k = power(k % d, d - 2, d);
        for (ll x : a) {
            ll r = x % d;
            if (r == 0) {
                cout << x << " ";
            } else {
                ll t = (d - r) * inv_k % d;
                cout << x + t * k << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}