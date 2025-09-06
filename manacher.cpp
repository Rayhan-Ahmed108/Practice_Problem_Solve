#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    string h = "";
    for(int i = 0; i < s.size(); i++) {
        h += '#' + s[i];
    }
}