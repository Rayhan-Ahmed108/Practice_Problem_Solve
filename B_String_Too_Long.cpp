// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long

void sol() {
    int n;
    cin >> n;

    string result = "";
    for (int i = 0; i < n; i++) {
        char ch;
        int cnt;
        cin >> ch >> cnt;
        if (cnt > 100 || result.size() + cnt > 100) {
            cout << "Too Long" << endl;
            return;
        }

        result += string(cnt, ch); 
    }
    cout << result << endl;
}

int32_t main() {
    FAST_IO
    sol();
}
