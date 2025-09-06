#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> S(n), T_arr(n);
        for (int i = 0; i < n; i++) cin >> S[i];
        for (int i = 0; i < n; i++) cin >> T_arr[i];

        int countS0 = 0, countT0 = 0;
        map<long long, int> mapS, mapT;

        for (auto s : S) {
            long long r = s % k;
            if (r == 0) {
                countS0++;
            } else {
                long long m = min(r, k - r);
                mapS[m]++;
            }
        }

        for (auto t_val : T_arr) {
            long long r = t_val % k;
            if (r == 0) {
                countT0++;
            } else {
                long long m = min(r, k - r);
                mapT[m]++;
            }
        }

        if (countS0 != countT0) {
            cout << "NO\n";
        } else {
            set<long long> allKeys;
            for (auto &p : mapS) allKeys.insert(p.first);
            for (auto &p : mapT) allKeys.insert(p.first);

            bool valid = true;
            for (auto key : allKeys) {
                int cntS = mapS.count(key) ? mapS[key] : 0;
                int cntT = mapT.count(key) ? mapT[key] : 0;
                if (cntS != cntT) {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
