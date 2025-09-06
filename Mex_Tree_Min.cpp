#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par = 0) {
    for (auto child : g[vertex]) {
        if (child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            depth[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
                
        dfs(1);
        int max_depth = 0, max_depth_vertex = 1;
        for (int i = 1; i <= n; i++) {
            if (depth[i] > max_depth) {
                max_depth = depth[i];
                max_depth_vertex = i;
            }
            depth[i] = 0;
        }
        dfs(max_depth_vertex);
        max_depth = 0;
        for (int i = 1; i <= n; i++) {
            max_depth = max(max_depth, depth[i]);
        }
        if (max_depth == n - 1) {
            cout << n * (n + 1) / 2 + (n - 1) << endl;
        } else {
            cout << (n - 1) + 2 << endl;
        }
    }
    return 0;
}
