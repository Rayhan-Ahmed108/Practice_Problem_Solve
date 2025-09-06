// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define pb push_back
#define in(n) int n; cin >> n;
#define pq priority_queue<pair<int,int>>
#define lll __int128_t
#define lb lower_bound
#define ub upper_bound
#define vi vector<int>
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n";

#ifdef DEBUG
#include <algo/debug.h>
#else
#define clog if (0) cerr
#define NB 40
#define db(...) ""
#endif

const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5;

int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};

const int dx1[] = {-1, 1, 0, 0}; // up, down, left, right
const int dy1[] = {0, 0, -1, 1};

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int t[N + 1][18]; 
map<int, int> mp1; 

void build(int n) {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            t[i][j] = max(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int length = r - l + 1;
    int j = 31 - __builtin_clz(length);
    return max(t[l][j], t[r - (1 << j) + 1][j]);
}

void sol() {
    for (int i = 1; i <= N; i++) {
        t[i][0] = 0;
    }
    mp1.clear();

    for (int i = 1; i * i <= N; i++) {
        int sq = i * i;
        for (int j = sq; j <= N; j += sq) {
            t[j][0]++;
            int ans = t[j][0];
            if (mp1.find(ans) == mp1.end()) {
                mp1[ans] = j;
            }
        }
    }
}

void sol1() {
    int n, m;
    cin >> n >> m;
    // for(int i = 1; i <= 16; i++) {
    //     cout << t[i][0] << ' ';
    // }
     int ans = query(n+1, m-1);
        cout << ans << endl;
}

int32_t main() {
    FAST_IO
    sol();
    build(N);
    int t; cin >> t;
    while (t--) {
        sol1();
    }
    return 0;
}
