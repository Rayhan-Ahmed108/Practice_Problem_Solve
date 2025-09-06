// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define FAST_IO                           \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
    }

using vi = vector<int>;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void sol() {
    int n, q;
    cin >> n >> q;
    vi v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    deque<int> q1;
    if (n >= 1) q1.push_front(v[1]);

    for (int i = 2; i <= n; ++i) {
        if (q1.size() < 2) {
            q1.push_back(v[i]);
        } else {
            int val_back = q1.back();
            int val_front = q1.front();
            q1.pop_back();
            q1.pop_front();

            q1.push_front(val_front);
            q1.push_back(val_back);

            if (val_back <= val_front) {
                if (i % 2 == 0) {
                    q1.push_front(v[i]);
                } else {
                    q1.push_back(v[i]);
                }
            } else {
                if (i % 2 == 0) {
                    q1.push_back(v[i]);
                } else {
                    q1.push_front(v[i]);
                }
            }
        }
    }
    if (!q1.empty()) {
        int need = min(q1.front(), q1.back());
        cout << need << '\n';
    } else {
        cout << 0 << '\n'; 
    }
}

int32_t main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
