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
#define pb      push_back
#define in(n)   int n; cin >> n;
#define pq      priority_queue<pair<int,int>>
#define lll     __int128_t
#define lb      lower_bound
#define ub      upper_bound
#define vi      vector<int>
#define print(ar)         for(auto x: ar) cout << x << " "; cout << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = 1e9 + 7;

void sol(){
    int n;
    cin >> n;
    vi v(n+2), pre(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    pre[n] = v[n];
    for(int i = n - 1; i >= 1; i--) {
        pre[i] = max(pre[i+1], v[i]);
    }

    for(int i = 1; i < n; i++) {
        if(v[i] < pre[i+1]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    cout << 0 << endl;
}
    
int32_t main()
{
    FAST_IO
    sol();
}
