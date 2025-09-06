#include <bits/stdc++.h>
using namespace std;

void is(const string &s, int n) {
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            count++;
            if (count > 1) {
                cout << "NO" << endl;
                return;
            }
        }
       
    }
    cout << "YES" << endl;
    return;
}
int main() {
    int n;
    string s;
    cin >> n >> s;
    is(s, n);
}
