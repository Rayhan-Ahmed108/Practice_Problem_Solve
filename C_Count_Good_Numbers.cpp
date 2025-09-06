#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll f(ll n) {
    if (n == 0) return 0;
    static vector<ll> denom;
    static vector<int> sign_factor;
    if (denom.empty()) {
        vector<int> primes = {2, 3, 5, 7};
        int total_mask = 1 << 4;
        for (int mask = 1; mask < total_mask; mask++) {
            ll d = 1;
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                if (mask & (1 << i)) {
                    d *= primes[i];
                    cnt++;
                }
            }
            denom.push_back(d);
            sign_factor.push_back((cnt % 2 == 1) ? 1 : -1);
        }
    }
    ll res = 0;
    for (int i = 0; i < 15; i++) {
        res += sign_factor[i] * (n / denom[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll total = r - l + 1;
        ll bad_r = f(r);
        ll bad_l_minus = f(l - 1);
        ll ans = total - (bad_r - bad_l_minus);
        cout << ans << '\n';
    }
    return 0;
}