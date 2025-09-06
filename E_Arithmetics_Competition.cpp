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
#define pq1      priority_queue<int, vector<int>, greater<int>> pq1;

#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define NB 40
#   define db(...) "" 
#endif

const long long INF = 1e18;
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};
#define FAST_IO                           \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
    }
#define mp make_pair
const int mod = 1e9 + 7;
#define endl "\n"
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int mod_sub(int a, int b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}
int binexp( int a,int b){ int ans=1; a=a%mod; while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}




int legend(int n, int x) {
    int ans = 0;
    while(n) {
        ans += (n / x);
        n /= x;
    }
    return ans;
}

bool isSquare(int n) {
    if (n < 0) return false; 
        int root = sqrt(n);
            return root * root == n;
}
const int dx1[] = {-1, 1, 0, 0}; //up, down, left, right
const int dy1[] = {0, 0, -1, 1};

// bool isValid(int x, int y) {
//     return (x >= 0 && x < n && y >= 0 && y < m);
// }
const int N = 2e5+8;
vector<pair<int, int>> v(N), v1(N), v2(N+N+5);
vector<int>pre(N), pre1(N);
int t[4*N];

void built(int node, int b, int e) {
    if(b == e) {
        t[node] = (v2[b].second == 1);
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    built(l, b, mid);
    built(r, mid + 1, e);
    t[node] = t[l] + t[r];
}
int query(int node, int b, int e, int i, int j) {
    if(b > j or e < i) return 0;
    if(b >= i and e <= j) {
        return t[node];
    }
    int l = 2 * node, r = l + 1;
    int mid  = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void sol() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = 1; 
    }
    for (int i = 1; i <= m; i++) {
        cin >> v1[i].first;
        v1[i].second = 2; 
    }

    sort(v.begin() + 1, v.begin() + n + 1);
    sort(v1.begin() + 1, v1.begin() + m + 1);

    int k = 0;
    for (int i = 1; i <= n; i++) v2[++k] = v[i];
    for (int i = 1; i <= m; i++) v2[++k] = v1[i];
    int tot = n + m;
    sort(v2.begin() + 1, v2.begin() + tot + 1);
    built(1, 1, tot);

    for (int i = 1; i <= n; i++) {
        pre[i] = (i == 1) ? v[i].first : pre[i - 1] + v[i].first;
    }
    for (int i = 1; i <= m; i++) {
        pre1[i] = (i == 1) ? v1[i].first : pre1[i - 1] + v1[i].first;
    }

    while (q--) {
        int x, y, z; 
        cin >> x >> y >> z;
        if(x + y == z) {
            cout << pre[n] - pre[ n - x] + pre1[m] - pre[m - y] << endl;
            continue;
        }
        int len = min<long long>(x + y, tot);
        if (len <= 0) { cout << 0 << '\n'; continue; }

        int L = tot - len + 1;
        int R = tot;

        int ans = query(1, 1, tot, L, R);
        if(ans <= x) {
            int nibo_from_x = min(x, z);
            int res = pre[n] - pre[n - nibo_from_x];
            int baki = 
        }
    }
}

    
int32_t main()
{
    FAST_IO
    int t;
    cin >> t;
    while(t--)
    sol();
}