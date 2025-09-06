// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define yes     cout << "YES\n";
#define no      cout << "NO\n"; 
#define pb      push_back
#define in(n)   int n; cin >> n;
#define pq      priority_queue<pair<int,int>>
#define lll     __int128_t
#define lb      lower_bound
#define ub      upper_bound
#define vi      vector<int>
#define print(ar) for(auto x: ar) cout<<x<<" "; cout<<"\n";
#define pq1      priority_queue<int, vector<int>, greater<int>> 

const long long INF = 1e18;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair
const int mod = 1e9 + 7;
#define endl "\n"

void sol(){
    int n;
    cin >> n;
    vector<pair<int,int>> pr(n);
    for(int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second;
    }

    int lo = 0, hi = 1e9, res = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int mn = 0, mx = 0;
        bool ok = true;

        for(int i = 0; i < n; i++) {
            int l = pr[i].first, r = pr[i].second;
            mn = max(l, mn - mid);
            mx = min(r, mx + mid);
            if(mn > mx) {
                ok = false;
                break;
            }
        }

        if(ok) {
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
}
    
int32_t main()
{
    FAST_IO
    int t;
    cin >> t;
    while(t--) sol();
}
