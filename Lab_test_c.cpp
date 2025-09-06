#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
vector<int> g[N];
vector<pair<int, int>>gra[N];
bool vis[N];

void dfs(int vertex) {
    vis[vertex] = true;
    for (auto i : g[vertex]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}
int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
    cout << "Case #" << k << ' ' << ':' << ' ';    
    int n, e;
    cin >> n >> e;
    set<int>s;
    for(int i = 0; i < e; i++) {
        g[i].clear();
        gra[i].clear();
        vis[i] = false;
    }
    for (int i = 0; i < e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
        gra[x].push_back({y, z});
        gra[y].push_back({x, z});
        s.insert(z);
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }
    if (count > 1) {
        cout << "No way" << endl;
    } 
    else if(s.size() <= 1) {
        cout << "No second way" << endl;
    }
    for(int i = 0; i < e; i++) {
        g[i].clear();
        gra[i].clear();
        vis[i] = false;
    }
}
}
