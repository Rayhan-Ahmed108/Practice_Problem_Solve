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



void sol(){
int n, count = 0;
cin >> n;
string s;
cin >> s;
for(int i = 0; i < n; i++) {
    int ans = s[i] - '0';
    if(ans == 2 or ans == 3 or ans == 4 or ans == 5 or ans == 7 or ans == 9 or ans == 1) {
        s[i] = 'p';
        count++;
    }
    else {
        if(i >= 1) {
            if(s[i-2] == '1' and s[i-1] == '0' and s[i] == '0') {
                s[i-2] = 'q';
                s[i-1] = 'o';
                s[i] = 'o';
                count++;
            }
            else if(s[i-1] == '8' and s[i] == '1') {
                s[i-1] = 'a';
                s[i] = 'o';
                count++;
            }
            else if(s[i-1] == '1' and s[i] == '6') {
                s[i-1] = 'i';
                s[i] = 'i';
                count++;
            } 
        }
    }
}
cout << count << endl;
}

    
int32_t main()
{
    FAST_IO
    // int t;
    // cin >> t;
    // while(t--)
    sol();
}