#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int odd_pos = (n + 1) / 2; 
    int even_count = n / 2;

    if (even_count < odd_pos) {
        cout << "impossible'" << endl;
        return 0;
    }

    vector<int> evens, odds;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }

    vector<int> ans(n);
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 1) { 
            ans[i] = evens[e++];
        } else {
            ans[i] = odds[o++];
        }
    }

    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
