// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
using namespace std;

#define int     long long int
#define yes     cout << "Yes\n";
#define no      cout << "No\n"; 
#define all(x)  x.begin(), x.end()
#define pb      push_back
#define vi      vector<int>
#define print(ar) for(auto x: ar) cout << x << " "; cout << "\n";

const int mod = 1e9 + 7;
const long long INF = 1e18;
#define endl "\n"

int mod_mul(int a, int b) { a %= mod; b %= mod; return (a * b) % mod; }
int mod_add(int a, int b) { a %= mod; b %= mod; return (a + b) % mod; }
int mod_sub(int a, int b) { a %= mod; b %= mod; return (a - b + mod) % mod; }
int binexp(int a, int b) {
    int ans = 1; a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool is_sorted_vector(const vector<int> &v) {
    return is_sorted(v.begin(), v.end());
}

void sol() {
    int n; cin >> n;
    vector<int> v(n), b(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> zero, one;
    for (int i = 0; i < n; i++) {
        if (b[i]) one.pb(v[i]);
        else zero.pb(v[i]);
    }

    if (zero.empty()) {
        if (is_sorted_vector(one)) yes
        else no
    }
    else if (one.empty()) {
        if (is_sorted_vector(zero)) yes
        else no
    }
    else yes
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
