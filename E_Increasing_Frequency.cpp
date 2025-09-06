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
const int N = 5e5 + 9;
vector<vector<int>> pos(N + 1);
vector<int>v2(N, 0);
void rec(vector<int>&a) {
    int n = a.size();
     for (int x : a) pos[x].clear();
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < pos[i].size(); j++) {
            v2[pos[i][j]] = j + 1;
        }
    }
}

void sol(){
int n, c, temp = 0, count = 0;
cin >> n >> c;
vi a(n), feq(n+1);
for(int i = 0; i < n; i++) {
    cin >> a[i];
    feq[a[i]]++;
    if(a[i] == c) {
        count++;
        temp = i;
    }
}
rec(a);
map<int, int>m1, m2;
for(int i = 0; i < n; i++) {
    m1[a[i]] = i;
    m2[a[i]]++;
}
int ans = 0;
for(int i = 0; i < n; i++) {
    int last = m1[a[i]];
    int fr1 = v2[a[i]], fr2 = 0;
    if(i == 0) {
        if(a[i] == c) {
            fr2 = 0;
        }
    }
    else {
            fr2 = v2[i-1];
        }
    int tot = fr1 - fr2;
    int c_count_first = 0, c_count_last = count - v2[m1[a[i]] - 1];
    if(i == 0) {
        c_count_first = 0;
    }
    else {
        c_count_first = v2[temp];
    }
    ans = max(ans, max(c_count_first + c_count_last + tot, max(v2[i] + m2[c] - v2[i], v2[m1[a[i]]] + (v2[n-1] - v2[i]))));
}
cout << ans << endl;
}
int32_t main()
{
    FAST_IO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t;
    // cin >> t;
    // while(t--)
    sol();
}