#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int col[N];
bool vis[N];
bool flag;
int dfs(int vertex)
{
    vis[vertex] = true;
    for (auto child : g[vertex])
    {
        if (!vis[child])
        {
            col[child] = col[vertex] ^ 1;
            dfs(child);
        }
        else
        {
            if (col[child] == col[vertex])
            {
                flag = false;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}