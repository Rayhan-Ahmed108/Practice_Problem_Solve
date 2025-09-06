#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void basicIO() {
    int a, b;
    cin >> a >> b;
    a = abs(a), b = abs(b);
    if(a % b == 0) {
        cout << "divisible" << endl;
        return;
    }
    else {
        cout << "not divisible" << endl;
        return;
    }
}

int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ':' << ' ';
    // basicIO();
    // Your cpp code here  
    }
    return 0;
}
