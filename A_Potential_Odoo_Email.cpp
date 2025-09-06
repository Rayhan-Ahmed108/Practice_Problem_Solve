#include<bits/stdc++.h>
using namespace std;

int rec(int n) {
    if(n <= 0) return 0;
    cout << n << endl;
    return rec(n / 2);
}
int main() {
    int n;
    cin >> n;
    rec(n);
}
