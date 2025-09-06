#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,int> memo;

int grundy(long long x) {
    if (x == 0) return 0;
    if (memo.count(x)) return memo[x];
    set<int> s;
    s.insert(grundy(x/2));
    s.insert(grundy(x/3));
    s.insert(grundy(x/4));
    s.insert(grundy(x/5));
    s.insert(grundy(x/6));
    int g = 0;
    while (s.count(g)) g++;
    return memo[x] = g;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        long long a;
        int xorSum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a;
            xorSum ^= grundy(a);
        }
        if (xorSum) cout << "Henry\n";
        else cout << "Derek\n";
    }
    return 0;
}
