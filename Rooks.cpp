// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
#include <map>
#include <set>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int     long long int
#define yes     cout << "YES\n";
#define no      cout << "NO\n"; 
#define pb      push_back;
#define in(n)   int n; cin >> n;
#define pq      priority_queue<pair<int,int>>
#define lll     __int128_t
#define lb      lower_bound
#define ub      upper_bound
#define vi      vector<int>
#define print(ar)         for(auto x: arr)cout<<x<<" ";nl;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair
#define endl "\n"
const long long INF = 1e18;
const int mod = 1e9 + 7;

template <typename T> 
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod_mul(int a, int b) { a %= mod; b %= mod; return (a * b) % mod; }
int mod_add(int a, int b) { a %= mod; b %= mod; return (a + b) % mod; }

int n, m;
int dp[35][35];     
bool vis[35][35];  
int rec(int i, int j) {
    if (j == 0) return 1;
    if (i == 0) return 0;

    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true;
    int ans = rec(i - 1, j);
    int need = rec(i - 1, j - 1) * (n - j + 1) * 1LL;

    return dp[i][j] = ans + need;
}

void sol() {
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    cout << rec(n, m) << endl;
}

int32_t main() {
    FAST_IO
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cout << "Case " << k << ':' << ' ';
         sol();
    }
    return 0;
}
