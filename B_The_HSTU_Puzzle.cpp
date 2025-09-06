#include <bits/stdc++.h>
using namespace std;

#define yes cout << "YES\n";
#define no cout << "NO\n";

#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> required = {'H', 'S', 'T', 'U'};
    set<char> present;

    for (char c : s) {
        if (required.count(c)) {
            present.insert(c);
        }
    }

    if (present.size() == 4) yes
    else no
}

int32_t main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
