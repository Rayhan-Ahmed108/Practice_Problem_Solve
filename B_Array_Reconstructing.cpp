// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int     long long int
#define yes     cout << "YES\n";
#define no      cout << "NO\n"; 
#define pb      push_back
#define in(n)   int n; cin >> n;
#define pq      priority_queue<pair<int,int>>
#define lll     __int128_t
#define lb      lower_bound
#define ub      upper_bound
#define vi      vector<int>
#define endl    "\n"

const int mod = 1e9 + 7;
const long long INF = 1e18;

int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int mod_mul(int a, int b) {a %= mod; b %= mod; return (a * b) % mod;}
int mod_add(int a, int b) {a %= mod; b %= mod; return (a + b) % mod;}
int mod_sub(int a, int b) {a %= mod; b %= mod; return ((a - b + mod) % mod);}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b) {return a * b / __gcd(a, b);}
int binexp(int a, int b) {int res = 1; a %= mod; while(b) { if(b&1) res = res * a % mod; a = a * a % mod; b >>= 1; } return res;}

void sol() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == -1) count++;
    }

    if(v[0] != -1) {
        for(int i = 0; i < n; i++) {
            if(v[i] == -1)
                v[i] = (v[i-1] + 1) % m;
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }

    if(count == n) {
        for(int i = 0; i < n; i++) {
            cout << (i % m) << " ";
        }
        cout << endl;
        return;
    }

    int fn = -1;
    for(int i = 0; i < n; i++) {
        if(v[i] != -1) {
            fn = i;
            break;
        }
    }
    for(int i = fn - 1; i >= 0; i--) {
        v[i] = (v[i+1] - 1 + m) % m;
    }
    for(int i = fn + 1; i < n; i++) {
        if(v[i] == -1)
            v[i] = (v[i-1] + 1) % m;
    }

    for(auto val : v) cout << val << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) sol();
}
