#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e6 + 6;
int divisorCount[MAXN + 1];

void precompute_divisor_count() {
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            divisorCount[j]++;
        }
    }
}

int32_t main() {
    FAST_IO;
    precompute_divisor_count();

    int t; cin >> t;
    string output;
    output.reserve(t * 4);

    while (t--) {
        int n, m; cin >> n >> m;
        int g = __gcd(n, m);
        output += to_string(divisorCount[g]);
        output += '\n';
    }
    cout << output;
}
