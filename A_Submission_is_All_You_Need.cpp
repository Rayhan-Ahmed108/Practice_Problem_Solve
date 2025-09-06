#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }

        if (s < total) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
                if (i < n - 1) 
                    cout << " ";
                else 
                    cout << endl;
            }
        } else if (s == total) {
            cout << "-1" << endl;
        } else {
            if (s == total + 1) {
                vector<int> zeros, ones, twos;
                for (int x : a) {
                    if (x == 0) 
                        zeros.push_back(0);
                    else if (x == 1) 
                        ones.push_back(1);
                    else if (x == 2) 
                        twos.push_back(2);
                }
                vector<int> b;
                for (int x : zeros) b.push_back(x);
                for (int x : twos) b.push_back(x);
                for (int x : ones) b.push_back(x);
                for (int i = 0; i < b.size(); i++) {
                    cout << b[i];
                    if (i < b.size() - 1) 
                        cout << " ";
                    else 
                        cout << endl;
                }
            } else {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}