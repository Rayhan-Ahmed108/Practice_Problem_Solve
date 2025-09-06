// ALLAH IS ALMIGHTY
// NEVER GIVE UP JEYAM
// TRY TRY & TRY

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 10000;
vector<int> primes;
vector<bool> isPrime(MAX + 100, true);

void Primes() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

set<int> bp() {
    set<int> s1;
    for (int i = 1; i + 1 < primes.size(); ++i) {
        int prev = primes[i - 1];
        int next = primes[i + 1];
        if ((prev + next) / 2 == primes[i] && (prev + next) % 2 == 0) {
            s1.insert(primes[i]);
        }
    }
    return s1;
}
bool sol(int a, int b, int c, int d) {
    for(int i = 0; i <= d; i++) {
        int sum = a * i * i + b * i + c;
        if(sum == d) return true;
    }
    return false;
}

int32_t main() {
    Primes();
    set<int> s = bp();

    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    vector<int>v;
    for (int d : s) {
        if (sol(a, b, c, d)) {
            v.push_back(d);
            count++;
        }
    }
    if(count == 0) {
        cout << -1 << endl;
    }
     else cout << count << "\n";
     for(auto it : v) {
        cout << it << ' ';
    }
    
    return 0;
}
