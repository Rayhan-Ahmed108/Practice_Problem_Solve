// ALLAH IS ALMIGHTY
#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> adj[200005];
int depth[200005], subsize[200005];

void dfs(int u, int parent) {
    subsize[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subsize[u] += subsize[v];
    }
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(depth[i] - subsize[i] + 1);
    }
    sort(v.rbegin(), v.rend());

    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += v[i];
    }

    cout << ans << "\n";
}
